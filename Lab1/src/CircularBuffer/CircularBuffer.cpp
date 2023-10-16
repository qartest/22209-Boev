#include <algorithm>
#include <stdexcept>
#include "CircularBuffer.h"

namespace Function{

	int SavePlus(int digit, int capacity, int plus) {
		return (digit + plus) % capacity;
	}

	int SaveMinus(int digit, int capacity) {
		return ((capacity - 1) * (digit == 0) + (digit != 0) * (digit - 1)) % capacity;
	}
}


CircularBuffer::CircularBuffer() {
	buffer = new value_type[1];
	capacity_ = 1;
	begin = 0;
	end = 0;
	size_ = 0;
}

CircularBuffer::CircularBuffer(int capacity) {
	if (capacity <= 0) {
		capacity = 1;
	}
	buffer = new value_type[capacity];
	capacity_ = capacity;
	begin = 0;
	end = 0;
	size_ = 0;
}


CircularBuffer :: ~CircularBuffer() {
	operator delete[](buffer);
}

CircularBuffer::CircularBuffer(const CircularBuffer & cb) {
	capacity_ = cb.capacity_;

	size_ = cb.size_;
	begin = cb.begin;
	end = cb.end;

	buffer = new value_type[cb.capacity_];
	for (int i = 0; i < cb.capacity_; ++i) {
		buffer[i] = cb.buffer[i];

	}
}


CircularBuffer::CircularBuffer(int capacity, const value_type & elem) : CircularBuffer(capacity) {
	for (int i = 0; i < capacity; ++i) {
		buffer[i] = elem;
	}
	end = capacity - 1;
	size_ = capacity;

}

value_type & CircularBuffer :: operator[](int i) {
	return buffer[Function::SavePlus(begin, capacity_, i)];
}

const value_type & CircularBuffer :: operator[](int i) const {
	return buffer[Function::SavePlus(begin, capacity_, i)];
}


value_type & CircularBuffer::at(int i) {

	if (i < size_) {
		return buffer[Function::SavePlus(begin, capacity_, i)];
	}
	else {
		throw std::out_of_range("Invalid Index");
	}
}

const value_type & CircularBuffer::at(int i) const {

	if (i < size_) {
		return buffer[Function::SavePlus(begin, capacity_, i)];
	}
	else {
		throw std::out_of_range("Invalid Index");
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
	if (capacity_ > 0) {
		if (size_ < capacity_) {
			size_++;
		}

		if (size_ != 1) {
			end = Function::SavePlus(end, capacity_, 1);
		}

		buffer[end] = item;

		if ((end == begin) && (size_ == capacity_)) {
			begin = Function::SavePlus(begin, capacity_, 1);
		}
	}

}

void CircularBuffer::push_front(const value_type & item = value_type()) {
	if (capacity_ > 0) {
		if (size_ != 0) {
			begin = Function::SaveMinus(begin, capacity_);
		}

		buffer[begin] = item;

		if (size_ < capacity_) {
			size_++;
		}

		if ((begin == end) && (size_ == capacity_)) {
			end = Function::SaveMinus(end, capacity_);
		}
	}



}

void CircularBuffer::pop_back() {
	if (size_ > 0) {
		end = Function::SaveMinus(end, capacity_);
		--size_;
	}
}

void CircularBuffer::pop_front() {
	if (size_ > 0) {
		begin = Function::SavePlus(begin, capacity_, 1);
		--size_;
	}
}

void CircularBuffer::rotate(int new_begin) {

	new_begin = new_begin < 0? 0: new_begin;
	new_begin = new_begin < size_? new_begin: 0;
	if(begin > end){
		std::rotate(&buffer[end+1], &buffer[begin], &buffer[capacity_]);
		std::rotate(&buffer[0], &buffer[end+1], &buffer[size_]);		
	}
	else{
		std::rotate(&buffer[0], &buffer[begin], &buffer[end+1]);		
	}
	std::rotate(&buffer[0], &buffer[new_begin], &buffer[size_]);

	begin = 0;
	end = size_ - 1;
}

value_type * CircularBuffer::linearize() {
	rotate(0);
	return &buffer[begin];
}

bool CircularBuffer::is_linearized() const {
	return begin == 0;
}


int CircularBuffer::size() const {
	return size_;
}

bool CircularBuffer::empty() const {
	return (size_ == 0);
}

int CircularBuffer::capacity() const {
	return capacity_;
}

bool CircularBuffer::full() const {
	return (size_ == capacity_);
}

int CircularBuffer::reserve() const {
	return capacity_ - size_;
}


void CircularBuffer::resize(int new_size, const value_type & item = value_type()) {
	int new_size_ = 0;
	new_size == 0 ? new_size = 1, new_size_ = -1: new_size = new_size;
	value_type * new_buffer = new value_type[new_size];

	if (new_size < size_) {

		for (int i = end, k = new_size - 1; (i != begin) && (k > -1); i = Function::SaveMinus(i, capacity_), k--) {
			new_buffer[k] = buffer[i];
			new_size_++;
		}
		size_ = new_size_;
		end = new_size - 1;
	}
	else {
		if(size_ != 0){

			for (int k = 0, i = begin; i != end; k++,  i = Function::SavePlus(i, capacity_, 1)) {
				new_buffer[k] = buffer[i];
				new_size_++;
			}

			new_buffer[new_size_] = buffer[end];
			new_size_++;
		}

		for (int i = new_size_; i < new_size; ++i) {
			new_buffer[i] = item;
		}
		if (item == value_type()) {
			size_ = new_size_;
			end = new_size_ - 1;
		}
		else{
			size_ = new_size;
			end = new_size - 1;
		}

	}

    begin = 0;	
	capacity_ = new_size;
	value_type * for_delete = buffer;
	buffer = new_buffer;
	operator delete[](for_delete);

}

void CircularBuffer::set_capacity(int new_capacity) {
	resize(new_capacity, value_type());
}

CircularBuffer & CircularBuffer :: operator=(const CircularBuffer & cb) {
	value_type * for_delete = buffer;
	buffer = new value_type[cb.capacity_];
	capacity_ = cb.capacity_;
	end = cb.end;
	begin = cb.begin;
	size_ = cb.size_;
	for (int i = 0; i < capacity_; ++i) {
		buffer[i] = cb.buffer[i];
	}
	operator delete[](for_delete);
	return *this;
}

void CircularBuffer::Swap(CircularBuffer & cb) {
	std::swap(size_, cb.size_);
	std::swap(begin, cb.begin);
	std::swap(end, cb.end);
	std::swap(capacity_, cb.capacity_);
	std::swap(buffer, cb.buffer);

}

void CircularBuffer::insert(int pos, const value_type & item = value_type()) {
	int place = (begin + pos) % capacity_;
	buffer[place] = item;
}

void CircularBuffer::clear() {
	size_ = 0;
	begin = 0;
	end = 0;
}

void CircularBuffer::erase(int first, int last) {
	if ((first > -1) && (last <= capacity_) && (first < last)) {
		for (int i = 0; i < (capacity_ - last); ++i) {
			int from = (begin + last + i) % capacity_;
			int to = (begin + first + i) % capacity_;
			buffer[to] = buffer[from];
		}
		
		int step = last - first;
		size_ -= step;
		if (size_ == 0) {
			end = begin;
		}
		else {
			end = ((end - step) < 0) * (capacity_ + end - step) + ((end - step) > 0) * (end - step);
		}

	}
}

bool CircularBuffer :: operator==(const CircularBuffer & a) {
	if (size_ != a.size_) {
		return false;
	}
	int k = a.begin, m = begin;
	for(int i = 0; i < size_; ++i){

		if (buffer[m] != a.buffer[k]) {
			return false;
		}
		k = Function::SavePlus(k, a.capacity_, 1);
		m = Function::SavePlus(m, capacity_, 1);
	}
	return true;

}

bool CircularBuffer :: operator!=(const CircularBuffer & a) {
	return !(*this == a);
}
