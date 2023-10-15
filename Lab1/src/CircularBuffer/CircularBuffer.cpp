#define _CRT_SECURE_NO_WARNINGS
#include "CircularBuffer.h"
#include <iostream>

int  minimum(int first, int second) {
	if (first < second) {
		return first;
	}
	return second;
}
int max_del(int first, int second) {
	int answer = 0;
	for (int i = 1; i <= minimum(first, second); ++i) {
		if ((first % i == 0) && (second % i == 0)) {
			answer = i;
		}
	}
	return answer;
}

void  SwapValue(value_type * first, value_type * second) {
	value_type now = *first;
	*first = *second;
	*second = now;
}

int GoodPlus(int digit, int capacity, int plus) {
	return (digit + plus) % capacity;
}

int GoodMinus(int digit, int capacity) {
	return ((capacity - 1) * (digit == 0) + (digit != 0) * (digit - 1)) % capacity;
}

CircularBuffer::CircularBuffer() {
	buffer = new value_type[1];
	my_capacity = 1;
	begin = 0;
	end = 0;
	inventory = 0;
}

CircularBuffer::CircularBuffer(int capacity) {
	if (capacity <= 0) {
		capacity = 1;
	}
	buffer = new value_type[capacity];
	my_capacity = capacity;
	begin = 0;
	end = 0;
	inventory = 0;
}


CircularBuffer :: ~CircularBuffer() {
	operator delete[](buffer);
}

CircularBuffer::CircularBuffer(const CircularBuffer & cb) {
	my_capacity = cb.my_capacity;

	inventory = cb.inventory;
	begin = cb.begin;
	end = cb.end;

	buffer = new value_type[cb.my_capacity];
	for (int i = 0; i < cb.my_capacity; ++i) {
		buffer[i] = cb.buffer[i];

	}
}


CircularBuffer::CircularBuffer(int capacity, const value_type & elem) : CircularBuffer(capacity) {
	for (int i = 0; i < capacity; ++i) {
		buffer[i] = elem;
	}
	end = capacity - 1;
	inventory = capacity;

}

value_type & CircularBuffer :: operator[](int i) {
	return buffer[GoodPlus(begin, my_capacity, i)];
}

const value_type & CircularBuffer :: operator[](int i) const {
	return buffer[GoodPlus(begin, my_capacity, i)];
}


value_type & CircularBuffer::at(int i) {

	if (i < inventory) {
		return buffer[GoodPlus(begin, my_capacity, i)];
	}
	else {
		throw "Element outside buffer";
	}
}

const value_type & CircularBuffer::at(int i) const {

	if (i < inventory) {
		return buffer[GoodPlus(begin, my_capacity, i)];
	}
	else {
		throw "Element outside buffer";
	}
}

value_type & CircularBuffer::front() {
	return buffer[begin];
}

value_type & CircularBuffer::back() {
	return buffer[end];
}

const value_type & CircularBuffer::front() const {
	return buffer[begin];
}

const value_type & CircularBuffer::back() const {
	return buffer[end];
}

void CircularBuffer::push_back(const value_type & item = value_type()) {
	if (my_capacity > 0) {
		if (inventory < my_capacity) {
			inventory++;
		}

		if (inventory != 1) {
			end = GoodPlus(end, my_capacity, 1);
		}

		buffer[end] = item;

		if ((end == begin) && (inventory == my_capacity)) {
			begin = GoodPlus(begin, my_capacity, 1);
		}
	}

}

void CircularBuffer::push_front(const value_type & item = value_type()) {
	if (my_capacity > 0) {
		if (inventory != 0) {
			begin = GoodMinus(begin, my_capacity);
		}

		buffer[begin] = item;

		if (inventory < my_capacity) {
			inventory++;
		}

		if ((begin == end) && (inventory == my_capacity)) {
			end = GoodMinus(end, my_capacity);
		}
	}



}

void CircularBuffer::pop_back() {
	if (inventory > 0) {
		end = GoodMinus(end, my_capacity);
		--inventory;
	}
}

void CircularBuffer::pop_front() {
	if (inventory > 0) {
		begin = GoodPlus(begin, my_capacity, 1);
		--inventory;
	}
}

void CircularBuffer::rotate(int new_begin) {
	if (my_capacity > 0) {
		if (new_begin < inventory) {
			int our_begin = GoodPlus(begin, my_capacity, new_begin);
			int step = my_capacity - our_begin;

			for (int i = 0; i < max_del(my_capacity, step); ++i) {
				int start = (our_begin + i) % my_capacity;
				int now = (start + step) % my_capacity;
				value_type take = buffer[start];
				while (now != start) {
					SwapValue(&take, &buffer[now]);
					now = (now + step) % my_capacity;
				}
				SwapValue(&take, &buffer[now]);
			}
			
			end = GoodPlus(end, my_capacity, step);
			begin = GoodPlus(begin, my_capacity, step);
			
			for(int i = 0; i < new_begin; ++i){
				int from = begin + i;
				int to = end + i + 1;
				buffer[from] = buffer[to];
			}
			end = end + new_begin;
			begin = 0;
			 
		}
		else {
			throw "New begin is not in buffer";
		}
	}
}

value_type * CircularBuffer::linearize() {
	if (my_capacity > 0) {
		int step = my_capacity - begin;

		for (int i = 0; i < max_del(my_capacity, step); ++i) {
			int start = (begin + i) % my_capacity;
			int now = (start + step) % my_capacity;
			value_type take = buffer[start];
			while (now != start) {
				SwapValue(&take, &buffer[now]);
				now = (now + step) % my_capacity;
			}
			SwapValue(&take, &buffer[now]);
		}
		begin = 0;
		end = (end + step) % my_capacity;
	}
	return &buffer[begin];
}

bool CircularBuffer::is_linearized() const {
	if (begin == 0) {
		return true;
	}
	return false;
}


int CircularBuffer::size() const {
	return inventory;
}

bool CircularBuffer::empty() const {
	if (inventory == 0) {
		return true;
	}
	return false;
}

int CircularBuffer::capacity() const {
	return my_capacity;
}

bool CircularBuffer::full() const {
	if (inventory == my_capacity) {
		return true;
	}
	return false;
}

int CircularBuffer::reserve() const {
	return my_capacity - inventory;
}


void CircularBuffer::resize(int new_size, const value_type & item = value_type()) {
	int new_inventory = 0;
	new_size == 0 ? new_size = 1, new_inventory = -1: new_size = new_size;
	value_type * new_buffer = new value_type[new_size];

	if (new_size < inventory) {

		for (int i = end, k = new_size - 1; (i != begin) && (k > -1); i = GoodMinus(i, my_capacity), k--) {
			new_buffer[k] = buffer[i];
			new_inventory++;
		}
		inventory = new_inventory;
		end = new_size - 1;
	}
	else {
		if(inventory != 0){

			for (int k = 0, i = begin; i != end; k++,  i = GoodPlus(i, my_capacity, 1)) {
				new_buffer[k] = buffer[i];
				new_inventory++;
			}

			new_buffer[new_inventory] = buffer[end];
			new_inventory++;
		}

		for (int i = new_inventory; i < new_size; ++i) {
			new_buffer[i] = item;
		}
		if (item == value_type()) {
			inventory = new_inventory;
			end = new_inventory - 1;
		}
		else{
			inventory = new_size;
			end = new_size - 1;
		}

	}

    begin = 0;	
	my_capacity = new_size;
	value_type * for_delete = buffer;
	buffer = new_buffer;
	operator delete[](for_delete);

}

void CircularBuffer::set_capacity(int new_capacity) {
	resize(new_capacity, value_type());
}

CircularBuffer & CircularBuffer :: operator=(const CircularBuffer & cb) {
	value_type * for_delete = buffer;
	buffer = new value_type[cb.my_capacity];
	my_capacity = cb.my_capacity;
	end = cb.end;
	begin = cb.begin;
	inventory = cb.inventory;
	for (int i = 0; i < my_capacity; ++i) {
		buffer[i] = cb.buffer[i];
	}
	operator delete[](for_delete);
	return *this;
}

void CircularBuffer::Swap(CircularBuffer & cb) {
	CircularBuffer now(cb);
	cb = *this;
	*this = now;
}

void CircularBuffer::insert(int pos, const value_type & item = value_type()) {
	int place = (begin + pos) % my_capacity;
	buffer[place] = item;
}

void CircularBuffer::clear() {
	inventory = 0;
	begin = 0;
	end = 0;
}

void CircularBuffer::erase(int first, int last) {
	if ((first > -1) && (last <= my_capacity) && (first < last)) {
		for (int i = 0; i < (my_capacity - last); ++i) {
			int from = (begin + last + i) % my_capacity;
			int to = (begin + first + i) % my_capacity;
			buffer[to] = buffer[from];
		}
		
		int step = last - first;
		inventory -= step;
		if (inventory == 0) {
			end = begin;
		}
		else {
			end = ((end - step) < 0) * (my_capacity + end - step) + ((end - step) > 0) * (end - step);
		}

	}
}

bool CircularBuffer :: operator==(const CircularBuffer & a) {
	if (my_capacity != a.my_capacity) {
		return false;
	}
	if (inventory != a.inventory) {
		return false;
	}
	if ((inventory == 0) || (a.inventory == 0)) {
		return true;
	}
	for (int i = begin, k = a.begin; i != end; i = GoodPlus(i, my_capacity, 1)) {

		if (buffer[i] != a.buffer[k]) {
			return false;
		}
		k = GoodPlus(k, a.my_capacity, 1);
	}

	if (buffer[end] != a.buffer[a.end]) {
		return false;
	}
	return true;

}

bool CircularBuffer :: operator!=(const CircularBuffer & a) {
	if (my_capacity != a.my_capacity) {
		return true;
	}
	if (inventory != a.inventory) {
		return true;
	}
	if ((inventory == 0) || (a.inventory == 0)) {
		return false;
	}

	for (int i = begin, k = a.begin; i != end; i = GoodPlus(i, my_capacity, 1)) {

		if (buffer[i] != a.buffer[k]) {
			return true;
		}
		k = GoodPlus(k, a.my_capacity, 1);
	}
	if ((inventory != 0) || (a.inventory != 0)) {
		if (buffer[end] != a.buffer[a.end]) {
			return true;
		}
	}
	return false;
}


