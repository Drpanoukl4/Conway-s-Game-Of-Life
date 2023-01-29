/*

Code By Gabriel Perez Cellular Auto




*/

#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Shadow : public olc::PixelGameEngine
{

struct sCell
{

	bool exist = false;

};

bool Ramdon () 
{

	return 0 + (rand() % (1 - 0 + 1)) == 1;
	//return rand() % 2;

}

public:
	Shadow()
	{
		sAppName = "Example";
	}
private:

	sCell* World;
	int nWorldHeihgt = 100;
	int nWorldWidth = 100;
	float fBlockWidth = 4.0f;
	sCell* auxWorld;

	void Evaluate ()
	{
		auxWorld = new sCell[ nWorldHeihgt * nWorldWidth ];

		for( int x = 0; x < nWorldWidth; x ++ )
		{

			for( int y = 0; y < nWorldWidth; y ++ )
			{
				int NeighbourAlive = 0;

				//1		
				if( x > 0 && y > 0 )
				{

					if(World[(( y - 1 ) * nWorldWidth) + ( x - 1)].exist)
					{
						NeighbourAlive += 1;
					}

				}

				//2	
				if( y > 0 )
				{

					if(World[(( y - 1 ) * nWorldWidth) + x ].exist)
					{
						NeighbourAlive += 1;
					}

				}

				//3
				if( x < (nWorldWidth - 1) && y > 0 )
				{

					if(World[(( y - 1 ) * nWorldWidth) + ( x + 1 )].exist)
					{
						NeighbourAlive += 1;
					}

				}

				//4
				if( x > 0 )
				{

					if(World[(y  * nWorldWidth) + ( x - 1 )].exist)
					{
						NeighbourAlive += 1;
					}

				}

				//5
				if( x < (nWorldWidth - 1) )
				{

					if(World[(y * nWorldWidth) + ( x + 1 )].exist)
					{
						NeighbourAlive += 1;
					}

				}

				//6
				if( x > 0 && y < (nWorldWidth - 1) )
				{

					if(World[(( y + 1 ) * nWorldWidth) + ( x - 1 )].exist)
					{
						NeighbourAlive += 1;
					}

				}

				//7
				if( y < (nWorldWidth - 1) )
				{

					if(World[(( y + 1 ) * nWorldWidth) + x ].exist)
					{
						NeighbourAlive += 1;
					}

				}

				//8
				if( x < (nWorldWidth - 1) && y < (nWorldWidth - 1) )
				{

					if(World[(( y + 1 ) * nWorldWidth) + ( x + 1 )].exist)
					{
						NeighbourAlive += 1;
					}

				}

				if( World[(y * nWorldWidth) + x].exist )
				{

					auxWorld[(y * nWorldWidth) + x].exist = NeighbourAlive == 2 || NeighbourAlive == 3 ? true : false;

				}else 
				{

					auxWorld[(y * nWorldWidth) + x].exist = NeighbourAlive == 3 ? true : false;

				}

			} 

		}

		World = auxWorld;

	}

public:
	bool OnUserCreate() override
	{

		// Called once at the start, so create things here
		World = new sCell[ nWorldHeihgt * nWorldWidth ];

		//Generate Ramdon
		for( int x = 0; x < nWorldWidth; x ++ )
		{

			for( int y = 0; y < nWorldHeihgt; y ++ )
			{

				int i = (y  * nWorldWidth) + x;
				World[i].exist = Ramdon();

			}

		}

		//Gosper's Glider Gun
		/*World[(4  * nWorldWidth) + 0].exist = true;
		World[(5  * nWorldWidth) + 0].exist = true;
		World[(4  * nWorldWidth) + 1].exist = true;
		World[(5  * nWorldWidth) + 1].exist = true;
		World[(4  * nWorldWidth) + 10].exist = true;
		World[(5  * nWorldWidth) + 10].exist = true;
		World[(6  * nWorldWidth) + 10].exist = true;
		World[(3  * nWorldWidth) + 11].exist = true;
		World[(7  * nWorldWidth) + 11].exist = true;
		World[(2  * nWorldWidth) + 12].exist = true;
		World[(8  * nWorldWidth) + 12].exist = true;
		World[(2  * nWorldWidth) + 13].exist = true;
		World[(8  * nWorldWidth) + 13].exist = true;
		World[(3  * nWorldWidth) + 15].exist = true;
		World[(7  * nWorldWidth) + 15].exist = true;
		World[(4  * nWorldWidth) + 16].exist = true;
		World[(5  * nWorldWidth) + 16].exist = true;
		World[(6  * nWorldWidth) + 16].exist = true;
		World[(5  * nWorldWidth) + 17].exist = true;
		World[(2  * nWorldWidth) + 20].exist = true;
		World[(3  * nWorldWidth) + 20].exist = true;
		World[(4  * nWorldWidth) + 20].exist = true;
		World[(2  * nWorldWidth) + 21].exist = true;
		World[(3  * nWorldWidth) + 21].exist = true;
		World[(4  * nWorldWidth) + 21].exist = true;
		World[(1  * nWorldWidth) + 22].exist = true;
		World[(5  * nWorldWidth) + 22].exist = true;
		World[(0  * nWorldWidth) + 24].exist = true;
		World[(1  * nWorldWidth) + 24].exist = true;
		World[(5  * nWorldWidth) + 24].exist = true;
		World[(6  * nWorldWidth) + 24].exist = true;
		World[(2  * nWorldWidth) + 34].exist = true;
		World[(3  * nWorldWidth) + 34].exist = true;
		World[(2  * nWorldWidth) + 35].exist = true;
		World[(3  * nWorldWidth) + 35].exist = true;*/
		

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		//Draawing

		Clear(olc::WHITE);
		//Draw Blocks

		for(int x = 0; x < nWorldWidth; x++)
		{

			for(int y = 0; y < nWorldHeihgt; y ++)
			{

				if( World[(y * nWorldWidth) + x].exist ) 
				{

					FillRect( x * fBlockWidth, y * fBlockWidth, fBlockWidth, fBlockWidth, olc::BLACK );

				}else
				{

					FillRect( x * fBlockWidth, y * fBlockWidth, fBlockWidth, fBlockWidth, olc::WHITE );

				}

			}

		}

		Evaluate();

		int TotalALive = 0;

		for( int x = 0; x < nWorldWidth; x ++ )
		{

			for( int y = 0; y < nWorldWidth; y ++ )
			{

				if(World[(y * nWorldWidth) + x].exist)
				{

					TotalALive += 1;

				}else if(TotalALive <= 0) {  

					TotalALive = 0;

				}else{

					TotalALive - 1;

				}

			}
		}

		DrawString(5, 380, "Total Cells ALive : "  + std::to_string(TotalALive) , olc::BLUE);

		return true;
	}
};

int main()
{
	Shadow demo;
	if (demo.Construct(400, 400, 4, 4))
		demo.Start();

	return 0;
}
