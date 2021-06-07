#pragma once

class Floor {
private:
	int up_create[17]; //각층올라갈사람수
	int down_create[17];//각층내려갈사람수
	int up_target[17];//올라가는사람중 타켓인층
	int down_target[17];//내려가는사람중 타켓인층
public:
	Floor()//초기설정
	{
		for (int i = 0; i < 17; i++)
		{
			up_create[i] = 0;
			down_create[i] = 0;
			up_target[i] = 0;
			down_target[i] = 0;
		}
	}
	~Floor() {};
	int pget_up(int a)//private 값을 받기&리셋할수있게
	{
		return up_create[a];
	}
	int pget_down(int a)
	{
		return down_create[a];
	}
	int tget_up(int a)
	{
		return up_target[a];
	}
	int tget_down(int a)
	{
		return down_target[a];
	}
	void minus_pget_up(int a, int b)
	{
		up_create[a] -= b;
	}
	void minus_pget_down(int a, int b)
	{
		down_create[a] -= b;
	}
	void plus_pget_up(int a)
	{
		++up_create[a];
	}
	void plus_pget_down(int a)
	{
		++down_create[a];
	}
	void plus_tget_up(int a)
	{
		++up_target[a];
	}
	void plus_tget_down(int a)
	{
		++down_target[a];
	}
	

};


