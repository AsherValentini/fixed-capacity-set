#pragma once
#include <cstddef>
#include <array>
#include <type_traits>
#include <optional>
#include <vector>
#include <new>

template<typename T, std::size_t Capacity = 10>
class set {
	static_assert(Capacity>0, "set size cannot be zero");
public:
	set () : size_(0) {}

	bool insert (const T& item) noexcept {

		if(findIndex(item).has_value())
			return false;

		std::size_t slot = Capacity;
		for(std::size_t i=0; i<Capacity; ++i) {
			if(!used_[i]) {
				slot = i;
			}

		}

		if(slot == Capacity)
			return false; // full
		void* place = static_cast<void*>(&set_[slot]);
		::new (place) T(item);

		used_[slot] = true;
		size_++;
		return true;
	}
	bool count (const T& item) const {

		if(findIndex(item).has_value())
			return true;

		return false;
	}

	void erase (const T& item) {

		auto index = findIndex(item);

		if(!index.has_value())
			return;

		T* ptr = std::launder(reinterpret_cast<T*>(&set_[index.value()]));
		ptr->~T();
		used_[index.value()] = false;

	}

private:
	std::array<std::aligned_storage_t<sizeof(T), alignof(T)>, Capacity> set_;
	std::array<bool, Capacity> used_;

	std::size_t size_;

	std::optional<std::size_t> findIndex (const T& item) const {

		for(std::size_t i=0; i<Capacity; ++i) {
			if(used_[i]) {
				const T* p = std::launder(reinterpret_cast<const T*>(&set_[i]));
				if(*p == item)
					return i;
			}
		}
		return std::nullopt;
	}



};