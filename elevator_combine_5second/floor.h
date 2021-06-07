#pragma once

class Floor {
private:
	int up_create[17]; //�����ö󰥻����
	int down_create[17];//���������������
	int up_target[17];//�ö󰡴»���� Ÿ������
	int down_target[17];//�������»���� Ÿ������
public:
	Floor()//�ʱ⼳��
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
	int pget_up(int a)//private ���� �ޱ�&�����Ҽ��ְ�
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


