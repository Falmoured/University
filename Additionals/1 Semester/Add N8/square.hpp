#pragma once

namespace fal
{
	struct Point
	{
		int x, y;
	};

	class Foursquare
	{
	public:
		Foursquare() {}

		//Foursquare(Point M, Point M1);
		
		~Foursquare();

		double Perimeter();
		double Square();
		double GetSide();
		double GetD();
		void SetM(Point M);
		void SetM1(Point M1);

	private:
		Point m_M;
		Point m_M1;
		double m_D;
		double m_S;
	};
}