#define _CRT_SECURE_NO_WARNINGS
#pragma once

typedef char value_type;

class CircularBuffer {

	value_type * buffer;
	int my_capacity;
	int inventory;
	int begin;
	int end;

public:


	CircularBuffer();

	CircularBuffer(int capacity);

	~CircularBuffer();

	CircularBuffer(const CircularBuffer & cb);

	CircularBuffer(int capacity, const value_type & elem);

	value_type & operator[](int i);

	const value_type & operator[](int i) const;

	value_type & at(int i);

	const value_type & at(int i) const;

	value_type & front();

	value_type & back();

	const value_type & front() const;

	const value_type & back() const;

	void push_back(const value_type & item);

	void push_front(const value_type & item);

	void pop_back();

	void pop_front();

	value_type * linearize();

	bool is_linearized() const;

	void rotate(int new_begin);

	int size() const;

	bool empty() const;

	int capacity() const;

	bool full() const;

	int reserve() const;

	void resize(int new_size, const value_type & item);

	void set_capacity(int new_capacity);

	CircularBuffer & operator=(const CircularBuffer & cb);

	void Swap(CircularBuffer & cb);

	void insert(int pos, const value_type & item);

	void clear();

	void erase(int first, int last);

	bool operator==(const CircularBuffer & a);

	bool operator!=(const CircularBuffer & a);

};
