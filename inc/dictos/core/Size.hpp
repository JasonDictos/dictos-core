#pragma once

namespace dictos {

/**
 * The size class gives type saftey to values comprising of
 * a byte size, rather then passing around integers.
 */
class Size
{
public:
	constexpr explicit Size(int64_t byteValue) : m_byteValue(byteValue) {}
	constexpr explicit Size(long double byteValue) : m_byteValue((int64_t)byteValue) {}

	constexpr Size() : m_byteValue(0) { }

	constexpr operator int64_t () { return m_byteValue; }

	static constexpr Size bytes(long double number) { return Size(number); }
	static constexpr Size kilobytes(long double number) { return Size(number * 1024); }
	static constexpr Size megabytes(long double number) { return Size(number * 1024 * 1024); }
	static constexpr Size gigabytes(long double number) { return Size(number * 1024 * 1024 * 1024); }
	static constexpr Size terabytes(long double number) { return Size(number * 1024 * 1024 * 1024 * 1024); }

	Size(const Size &size) :
		m_byteValue(size.m_byteValue)
	{
	}

	Size & operator = (const Size &size)
	{
		m_byteValue = size.m_byteValue;
		return *this;
	}

	Size & operator += (const Size &size)
	{
		m_byteValue += size.m_byteValue;
		return *this;
	}

	Size & operator -= (const Size &size)
	{
		m_byteValue -= size.m_byteValue;
		return *this;
	}

	Size operator + (const Size &size) const noexcept
	{
		Size newSize(m_byteValue);

		newSize.m_byteValue += size.m_byteValue;

		return newSize;
	}

	Size operator - (const Size &size) const noexcept
	{
		Size newSize(m_byteValue);

		newSize.m_byteValue -= size.m_byteValue;

		return newSize;
	}

	template<class T = size_t>
	T asBytes() const
	{
		return numericCast<T>(m_byteValue);
	}

	constexpr bool operator < (const Size &size) const noexcept
	{
		return m_byteValue < size.m_byteValue;
	}

	constexpr bool operator <= (const Size &size) const noexcept
	{
		return m_byteValue <= size.m_byteValue;
	}

	constexpr bool operator > (const Size &size) const noexcept
	{
		return m_byteValue > size.m_byteValue;
	}

	constexpr bool operator >= (const Size &size) const noexcept
	{
		return m_byteValue >= size.m_byteValue;
	}

	constexpr bool operator == (const Size &size) const noexcept
	{
		return m_byteValue == size.m_byteValue;
	}

	constexpr bool operator != (const Size &size) const noexcept
	{
		return m_byteValue != size.m_byteValue;
	}

	explicit constexpr operator bool () const noexcept
	{
		 return m_byteValue != 0;
	}

	constexpr bool isNegative() const noexcept
	{
		return m_byteValue < 0;
	}

	constexpr bool isPositive() const noexcept
	{
		return m_byteValue > 0;
	}

	constexpr bool isZero() const noexcept
	{
		return m_byteValue == 0;
	}

	std::string __toString() const
	{
		return string::toString(m_byteValue, " bytes");
	}

	operator std::size_t () const { return m_byteValue; }

protected:
	int64_t m_byteValue;
};

}