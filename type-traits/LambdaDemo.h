#pragma once

template <typename T>
class Process
{
	T _cb;
public:
	Process(T p) : _cb(p) {}
	void Exec()
	{
		_cb();
	}
};
