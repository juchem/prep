#ifndef INCLUDED__color_h
#define INCLUDED__color_h

class color {
	unsigned value;

public:
	constexpr color(unsigned argb):
		value(argb)
	{
	}

	constexpr color(color const &) = default;

	constexpr color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 0xffu):
		value((r << 16) | (g << 8) | b | (a << 24))
	{
	}

	bool const operator !=(color const &other) const {
		return value != other.value;
	}

	bool const operator ==(color const &other) const {
		return value == other.value;
	}

	static constexpr color black() { return color(0xff000000u); }
	static constexpr color red() { return color(0xffff0000u); }
	static constexpr color green() { return color(0xff00ff00u); }
	static constexpr color blue() { return color(0xff0000ffu); }
	static constexpr color white() { return color(0xffffffffu); }
};

#endif // INCLUDED__color_h
