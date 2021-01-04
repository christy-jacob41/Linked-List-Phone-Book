/*
* MemoryLeak.h
*
*  Created on: Nov 9, 2017
*      Author: dgv130030
*/

#ifndef MEMORYLEAK_H_
#define MEMORYLEAK_H_

#include <cstdlib>
#include <iostream>
#include <map>
#include <memory>
#include <iomanip>
#include <limits>

class memoryLeak
{
	public:
		// the following code is based on the example code on cppreference.com at URL:
		// http://en.cppreference.com/w/cpp/concept/Allocator
		//
		template <class Type>
		class memoryLeakAllocator
		{
			public:
				typedef Type value_type;

				memoryLeakAllocator() = default;

				template <class OtherType>
				constexpr memoryLeakAllocator(const memoryLeakAllocator<OtherType>&) noexcept {}

				Type* allocate(std::size_t number)
				{
					if (number > std::numeric_limits<std::size_t>::max() / sizeof(Type))
					{
						throw std::bad_alloc();
					}

					if (auto ptr = static_cast<Type*>(std::malloc(number * sizeof(Type))))
					{
						return ptr;
					}

					throw std::bad_alloc();
				}
				void deallocate(Type* ptr, std::size_t) noexcept
				{
					std::free(ptr);
				}
		};

	// we are going to override the generic new and delete operators
	friend void* operator new(std::size_t size);
	friend void operator delete(void* ptrToFree) noexcept;
	friend void operator delete(void* ptrToFree, std::size_t size) noexcept;
	friend void* operator new[](std::size_t size);
	friend void operator delete[](void* ptrToFree) noexcept;
	friend void operator delete[](void* ptrToFree, std::size_t size) noexcept;

		static void verbose()
		{
			extraOutput = true;
		}

		static void quiet()
		{
			extraOutput = false;
		}

		static void summaryAtEnd()
		{
			summaryDisplay = true;
		}

		static void noSummaryAtEnd()
		{
			summaryDisplay = false;
		}

		static bool is_summaryAtEnd()
		{
			return summaryDisplay;
		}

		static bool is_verbose()
		{
			return extraOutput;
		}

		static bool is_quiet()
		{
			return !extraOutput;
		}
	private:
		// keep stats on new/delete operations
		static unsigned long long int allAllocated;
		static unsigned long long int allFreed;
		static unsigned long long int countAllocated;
		static unsigned long long int countFreed;
		static memoryLeak memory;
		static bool extraOutput;
		static bool summaryDisplay;
		// keep track of addresses and sizes of all allocated items
		// note we are using our own allocator so our versions of new and
		// delete are not called when adding / removing from the map.
		static std::map<const void*, std::size_t, std::less<const void*>, memoryLeakAllocator<std::pair<const void*, std::size_t>>> addressMap;

		// add the address and size to the map and update
		// stats
		static void allocate(void* address, std::size_t size)
		{
			if (extraOutput)
			{
				std::cout << "+++ new " << address << " (" << size << ")" << std::endl;
			}
			addressMap[address] = size;
			allAllocated += size;
			countAllocated++;
		}

		// remove the address from the map and update stats
		static bool deallocate(void* address)
		{
			bool result;
			try
			{
				std::size_t size = addressMap.at(address);
				if (extraOutput)
				{
					std::cout << "--- delete " << address << std::endl;
				}
				allFreed += size;
				countFreed++;
				addressMap.erase(address);
				result = true;
			}
			catch (std::out_of_range &err)
			{
				std::cout << "--- delete " << address << " (not allocated)" << std::endl;
				result = false;
			}

			return result;
		}

		// we are actually using malloc
		static void* actualNew(std::size_t size)
		{
			void* address = std::malloc(size);
			memoryLeak::allocate(address, size);
			return address;
		}

		// use free
		static void actualDelete(void* address)
		{
			bool valid = memoryLeak::deallocate(address);
			if (valid)
			{
				std::free(address);
			}
		}

	public:
		memoryLeak() {}

		virtual ~memoryLeak()
		{
			if (summaryDisplay)
			{
				summary();
			}
		}

		static void summary()
		{
			summary(std::cout);
		}
		static void summary(std::ostream &out)
		{
			if (summaryDisplay)
			{
				const unsigned int LEN1 = 20U;
				const unsigned int LEN2 = 10U;
				out << std::endl;
				out << "***** start of MemoryLeak::summary output" << std::endl;
				out << std::endl;
				if (addressMap.size() > 0)
				{
					out << "The following blocks of memory have been allocated but not freed:" << std::endl;
					out << std::setw(LEN1) << "Address" << std::setw(LEN2) << "Size" << std::endl;

					for (auto &elem : addressMap)
					{
						out << std::setw(LEN1) << elem.first << std::setw(LEN2) << elem.second << std::endl;
					}
					out << std::endl;
				}
				else
				{
					out << "All memory blocks have been freed" << std::endl;
					out << std::endl;
				}

				const unsigned int LEN3 = LEN1;
				const unsigned int LEN4 = LEN2;
				out << std::setw(LEN3) << "Amount allocated" << std::setw(LEN4) << allAllocated << std::endl;
				out << std::setw(LEN3) << "Amount freed" << std::setw(LEN4) << allFreed << std::endl;
				out << std::setw(LEN3) << "# new operations" << std::setw(LEN4) << countAllocated << std::endl;
				out << std::setw(LEN3) << "# delete operations" << std::setw(LEN4) << countFreed << std::endl;
				out << std::endl;
				out << "***** end of MemoryLeak::summary output" << std::endl;
				out << std::endl;
			}
		}
};

template <class Type, class Other>
bool operator==(const memoryLeak::memoryLeakAllocator<Type>&, const memoryLeak::memoryLeakAllocator<Other>&)
{
	return true;
}

template <class Type, class Other>
bool operator!=(const memoryLeak::memoryLeakAllocator<Type>&, const memoryLeak::memoryLeakAllocator<Other>&)
{
	return false;
}

//unsigned long long int MemoryLeak::allAllocated = 0ULL;
//unsigned long long int MemoryLeak::allFreed = 0ULL;
//unsigned long long int MemoryLeak::countAllocated = 0ULL;
//unsigned long long int MemoryLeak::countFreed = 0ULL;
//bool MemoryLeak::extraOutput = false;
//
//std::map<const void*, std::size_t, std::less<const void*>, MemoryLeak::MemoryLeakAllocator<std::pair<const void*, std::size_t>>> MemoryLeak::addressMap;
//MemoryLeak MemoryLeak::memory;
//
//void* operator new(std::size_t size)
//{
//	return MemoryLeak::actualNew(size);
//}
//
//void operator delete(void* ptrToFree) noexcept
//{
//	MemoryLeak::actualDelete(ptrToFree);
//}
//
//void operator delete(void* ptrToFree, std::size_t) noexcept
//{
//	MemoryLeak::actualDelete(ptrToFree);
//}
//
//void* operator new[](std::size_t size)
//{
//	return MemoryLeak::actualNew(size);
//}
//
//void operator delete[](void* ptrToFree) noexcept
//{
//	MemoryLeak::actualDelete(ptrToFree);
//}
//
//void operator delete[](void* ptrToFree, std::size_t) noexcept
//{
//	MemoryLeak::actualDelete(ptrToFree);
//}

#endif /* MEMORYLEAK_H_ */
