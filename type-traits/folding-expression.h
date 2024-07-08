#pragma once

template<typename ...Args>
auto  FoldingSum1(Args... args)
{
	return (args + ...);
}

template<typename ...Args>
auto  FoldingSum2(Args... args)
{
	return (args + ... + 0);
}
