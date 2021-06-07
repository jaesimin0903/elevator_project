#pragma once
#include<vector>
#include<algorithm> 


void move_arrange(vector<int> &a,Passengers &v1);//�迭�� <<������ �������ִ� ���������ִ� �Լ�

using namespace std;
class Elevators {
private:
	int present1;//���� ��
	int present2;
	int destination1;//������
	int destination2;
	int door_situation1;//������(������,����)=(1/0)
	int door_situation2;
	int elevator_state1;//1.���������� 2.�ö󰡴��� 3.����������
	int elevator_state2;
	int people1[3];//[0]. ������ �ִ������, [1]. ź�� �ٲ� �����, [2] ������ �ٲ� �����
	int people2[3];
	vector<int> take_passengers1;
	vector<int> take_passengers2;
	int take_passengerFIFO1[15];
	int timeStamp;
public:
	Elevators(int a = 0, int b = 0, int c = 16, int d = 16) :present1(a), destination1(b), present2(c), destination2(d)
	{//���������� �ʱ���� ����
		timeStamp = 0;

		door_situation1 = 0;
		door_situation2 = 0;
		elevator_state1 = 1;
		elevator_state2 = 1;
		for (int i = 0; i < 3; i++)
		{
			people1[i] = 0;
			people2[i] = 0;
		}
		for (int i = 0; i < 15; i++)
		{
			take_passengers1.push_back(1000);
			take_passengers2.push_back(1000);
			take_passengerFIFO1[i] = 0;
		}
	}
	~Elevators() {};


	int get_present1()
	{
		return present1;
	}
	int get_present2()
	{
		return present2;
	}
	int get_destination1()
	{
		return destination1;
	}
	int get_destination2()
	{
		return destination2;
	}
	int get_elevator_state1()
	{
		return elevator_state1;
	}
	int get_elevator_state2()
	{
		return elevator_state2;
	}
	int get_door1()
	{
		return door_situation1;
	}
	int get_door2()
	{
		return door_situation2;
	}
	int get_people1()
	{
		return people1[0];
	}
	int get_people1_2() {
		return people1[1];
	}
	int get_people1_3() {
		return people1[2];
	}
	int get_people2()
	{
		return people2[0];
	}
	void set_destination1(int a)
	{
		destination1 = a;
	}
	void set_destination2(int a)
	{
		destination2 = a;
	}
	void set_door1()
	{
		door_situation1 = 0;
	}
	void set_door2()
	{
		door_situation2 = 0;
	}
	int time_Stamp() {
		return timeStamp;
	}
	int get_take_passengers1(int a) {
		return take_passengers1[a];
	}
	int get_take_passengers2(int a) {
		return take_passengers2[a];
	}
	void Elevator_state();//���������� ���¼���
	void Elevator_move_take_in_out(Passengers &v1, Floor &v2);//���������� �ൿ, ����������
	void go_create_n(Floor &v1);//�������� ����
	void go_target_n(Passengers &v1);//����������ź��� ��������
	void take_in_out(Passengers &v1, Floor &v2);//���������� Ÿ����

	void go_create_np(Floor &v1);//�������� ����
	void go_target_np(Passengers &v1);//����������ź��� ��������

	void go_create_npp(Floor &v1);//�������� ����
	void go_target_npp(Passengers &v1);//����������ź��� ��������
	void take_in_out_npp(Passengers& v1, Floor& v2);

	void go_create_oe(Floor &v1);
	void take_in_out_oe(Passengers &v1, Floor &v2);

	void go_go();

	void take_in_outFIFO(Passengers& v1, Floor& v2);
};

void move_arrange(vector<int>& v, Passengers& v1)//�迭�� <<������ �������ִ� ���������ִ� �Լ�
{
	sort(v.begin(), v.end());
}

void Elevators::Elevator_state()//���������� ���¼���
{
	if (destination1 > present1)//����1����
		elevator_state1 = 2;
	else if (destination1 < present1)
		elevator_state1 = 3;
	else if (destination1 == present1)
		elevator_state1 = 1;


	if (destination2 > present2)//����2����
		elevator_state2 = 2;
	else if (destination2 < present2)
		elevator_state2 = 3;
	else if (destination2 == present2)
		elevator_state2 = 1;
}

void Elevators::Elevator_move_take_in_out(Passengers &v1, Floor &v2)//���������� �ൿ, ����������
{

	if (elevator_state1 == 1)//����������
	{
		//timeStamp++;
	}
	else if (elevator_state1 == 2)//�ö󰡴���
	{
		if (people1[0] == people1[1] && people1[1] == people1[2])//�մԾ��ٸ�
		{
			present1++;
			timeStamp++;
		}
		else//�մ��� �ִٸ�
		{
			door_situation1 = 1;//��������
			timeStamp++;

		}

	}
	else if (elevator_state1 == 3)//����������
	{
		if (people1[0] == people1[1] && people1[1] == people1[2])//�մԾ��ٸ�
		{
			present1--;
			timeStamp++;
		}
		else//�մ��� �ִٸ�
		{
			door_situation1 = 1;//��������
			timeStamp++;

		}
	}

	//����2
	if (elevator_state2 == 1)//����������
	{
		//timeStamp++;
	}
	else if (elevator_state2 == 2)//�ö󰡴���
	{
		if (people2[0] == people2[1] && people2[1] == people2[2])//�մԾ��ٸ�
		{
			present2++;
			timeStamp++;
		}
		else//�մ��� �ִٸ�
		{
			door_situation2 = 1;//��������
			timeStamp++;

		}

	}
	else if (elevator_state2 == 3)//����������
	{
		if (people2[0] == people2[1] && people2[1] == people2[2])//�մԾ��ٸ�
		{
			present2--;
			timeStamp++;
		}
		else//�մ��� �ִٸ�
		{
			door_situation2 = 1;//��������
			timeStamp++;

		}
	}

	people1[0] = people1[2];
	people1[1] = people1[2];
	people2[0] = people2[2];
	people2[1] = people2[2];




}

void Elevators::go_create_n(Floor &v1)//�������� ����
{
	for (int i = 0; i < 17; i++)
	{
		if (elevator_state1 == 2)///up
		{
			if (i > present1)//���������� ���� ��ġ���� ũ�ٸ�
			{
				if (v1.pget_up(i) != 0 && i > destination1)// ������ �ö󰥻���� �ְ� ���������� ���� �ִٸ�
					destination1 = i;
				if (v1.pget_down(i) != 0 && i > destination1)// ������ ����������� �ְ� ���������� ���� �ִٸ�
					destination1 = i;
			}
		}
		else if (elevator_state1 == 1)//stop
		{
			if (i > present1)
			{
				if (v1.pget_up(i) != 0 && i > destination1)
					destination1 = i;
				if (v1.pget_down(i) != 0 && i > destination1)
					destination1 = i;
			}
			else if (i < present1)
			{
				if (v1.pget_down(i) != 0 && i < destination1)
					destination1 = i;
				if (v1.pget_up(i) != 0 && i < destination1)
					destination1 = i;
			}
		}
		else if (elevator_state1 == 3)//down
		{
			if (i < present1)
			{
				if (v1.pget_down(i) != 0 && i < destination1)
					destination1 = i;
				if (v1.pget_up(i) != 0 && i < destination1)
					destination1 = i;
			}
		}

		//

		if (elevator_state2 == 2)
		{
			if (i > present2)
			{
				if (v1.pget_up(i) != 0 && i > destination2)
					destination2 = i;
				if (v1.pget_down(i) != 0 && i > destination2)
					destination2 = i;
			}
		}
		else if (elevator_state2 == 1)
		{
			if (i > present2)
			{
				if (v1.pget_up(i) != 0 && i > destination2)
					destination2 = i;
				if (v1.pget_down(i) != 0 && i > destination2)
					destination2 = i;
			}
			else if (i < present2)
			{
				if (v1.pget_down(i) != 0 && i < destination2)
					destination2 = i;
				if (v1.pget_up(i) != 0 && i < destination2)
					destination2 = i;
			}
		}
		else if (elevator_state2 == 3)
		{
			if (i < present2)
			{
				if (v1.pget_down(i) != 0 && i < destination2)
					destination2 = i;
				if (v1.pget_up(i) != 0 && i < destination2)
					destination2 = i;
			}
		}
	}

}

void Elevators::go_target_n(Passengers &v1)
{
	if (elevator_state1 == 2)//up
	{
		if (people1[0] != 0)//������ �ִ� ��� �� 0 �� �ƴ϶��
			destination1 = 0;//������ �ʱ�ȭ
		for (int i = 0; i < 15; i++)
		{

			if (take_passengers1[i] != 0)//������ ����� Ÿ�ִٸ�
			{
				if (destination1 < v1.get_target(take_passengers1[i]))//������������ ���������� Ÿ���ִ� ����� �������� ũ�ٸ�
					destination1 = v1.get_target(take_passengers1[i]);//������ ����
			}
		}
	}
	else if (elevator_state1 == 3)//down
	{

		for (int i = 0; i < 15; i++)
		{
			if (people1[0] != 0)
				destination1 = 16;
			if (take_passengers1[i] != 0)
			{
				if (destination1 > v1.get_target(take_passengers1[i]))
					destination1 = v1.get_target(take_passengers1[i]);
			}
		}
	}

	//

	if (elevator_state2 == 2)
	{
		if (people2[0] != 0)
			destination2 = 0;
		for (int i = 0; i < 15; i++)
		{

			if (take_passengers2[i] != 0)
			{
				if (destination2 < v1.get_target(take_passengers2[i]))
					destination2 = v1.get_target(take_passengers2[i]);
			}
		}
	}
	else if (elevator_state2 == 3)
	{
		if (people2[0] != 0)
			destination2 = 16;
		for (int i = 0; i < 15; i++)
		{
			if (take_passengers2[i] != 0)
			{
				if (destination2 > v1.get_target(take_passengers2[i]))
					destination2 = v1.get_target(take_passengers2[i]);
			}
		}
	}
}

void Elevators::take_in_out(Passengers &v1, Floor &v2)
{

	for (int i = 0; i <= v1.get_person(); i++)//���������� Ÿ�ºκ�
	{



		if (present1 == v1.get_create(i))//Ÿ�°Ͱ��� ����1��
		{
			if (elevator_state1 == 1 && people1[1] < 15)//������ �����ΰ�� �ȿ� �մԾ��ٴ¶�!
			{
				if (v1.get_act(i) == 1)//�ö� �մ�~
				{
					v2.minus_pget_up(present1, 1);
					take_passengers1[people1[1]] = i;//ź���� ��� 
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 2;//������ ���οö󰥻���� ���������� ���������͸� ���οö󰡴»��·ιٲ���
				}
				else if (v1.get_act(i) == 2)//������ �մ�~
				{
					v2.minus_pget_down(present1, 1);
					take_passengers1[people1[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 3;
				}
			}
			else if (elevator_state1 == 2)//��
			{
				if (v1.get_act(i) == 1)//�ö󰥻���϶�
				{
					if (people1[1] < 15)//15���� ������ �� Ż������
					{
						v2.minus_pget_up(present1, 1);
						take_passengers1[people1[1]] = i;//�׻���� ������ ����
						v1.take_up(i);//�� ��� ź���·�
						v1.set_act(i);
						people1[1]++;//ź��� ����
					}
				}
			}
			else if (elevator_state1 == 3)//�Ʒ�
			{
				if (v1.get_act(i) == 2)//�������»��
				{
					if (people1[1] < 15)
					{
						v2.minus_pget_down(present1, 1);
						take_passengers1[people1[1]] = i;
						v1.take_up(i);
						v1.set_act(i);
						people1[1]++;
					}
				}
			}
		}


		if (present2 == v1.get_create(i))//Ÿ�°Ͱ��� ����2��
		{
			if (elevator_state2 == 1)//������ �����ΰ�� �ȿ� �մԾ��ٴ¶�!
			{
				if (v1.get_act(i) == 1)//�ö� �մ�~
				{
					v2.minus_pget_up(present2, 1);
					take_passengers2[people2[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					elevator_state2 = 2;//������ ���οö󰥻���� ���������� ���������͸� ���οö󰡴»��·ιٲ���
				}
				else if (v1.get_act(i) == 2)//������ �մ�~
				{
					v2.minus_pget_down(present2, 1);
					take_passengers2[people2[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					elevator_state2 = 3;
				}
			}
			else if (elevator_state2 == 2)//��
			{
				if (v1.get_act(i) == 1)//�ö󰥻���϶�
				{
					if (people2[1] < 15)//15���� ������ �� Ż������
					{
						v2.minus_pget_up(present2, 1);
						take_passengers2[people2[1]] = i;//�׻���� ������ ����
						v1.take_up(i);//�� ��� ź���·�
						v1.set_act(i);
						people2[1]++;//ź��� ����

					}
				}
			}

			else if (elevator_state2 == 3)//�Ʒ�
			{
				if (v1.get_act(i) == 2)//�������»��
				{
					if (people2[1] < 15)
					{
						v2.minus_pget_down(present2, 1);
						take_passengers2[people2[1]] = i;
						v1.set_act(i);
						v1.take_up(i);
						people2[1]++;

					}
				}
			}
		}
	}
	//������ �κ�
	people1[2] = people1[1];//people[2]�� �������� �մԼ��� �ǵ���
	people2[2] = people2[1];

	for (int i = 0; i < 15; i++)
	{//����1
		if (present1 == v1.get_target(take_passengers1[i]) && v1.get_take(take_passengers1[i]) == 1)// ���� Ÿ���ִ»���� �������� �������� ������
		{
			v1.take_down(take_passengers1[i]);//���������ŷ� ����
			people1[2]--;//�ȿ� �������
			take_passengers1[i] = 1000;

		}

		//����2
		if (present2 == v1.get_target(take_passengers2[i]) && v1.get_take(take_passengers2[i]) == 1)
		{
			v1.take_down(take_passengers2[i]);
			people2[2]--;
			take_passengers2[i] = 1000;

		}


	}

	move_arrange(take_passengers1,v1);
	move_arrange(take_passengers2,v1);
}

void Elevators::go_create_np(Floor &v1)//�������� ����
{
	for (int i = 0; i < 17; i++)
	{
		if (elevator_state1 == 2)
		{
			if (v1.pget_up(i) != 0 && i > destination1)
				destination1 = i;
			if (v1.pget_down(i) != 0 && i > destination1)
				destination1 = i;
			else if (elevator_state2 == 2)
			{
				if (v1.pget_up(i) != 0 && i > destination2)
					destination2 = i;
				if (v1.pget_down(i) != 0 && i > destination2)
					destination2 = i;
			}
		}
		if (elevator_state1 == 1)
		{
			if (i > present1)
			{
				if (v1.pget_up(i) != 0 && i > destination1)
					destination1 = i;
				if (v1.pget_down(i) != 0 && i > destination1)
					destination1 = i;
			}
			else if (i < present1)
			{
				if (v1.pget_down(i) != 0 && i < destination1)
					destination1 = i;
				if (v1.pget_up(i) != 0 && i < destination1)
					destination1 = i;
			}
		}
		else if (elevator_state2 == 1)
		{
			if (i > present2)
			{
				if (v1.pget_up(i) != 0 && i > destination2)
					destination2 = i;
				if (v1.pget_down(i) != 0 && i > destination2)
					destination2 = i;
			}
			else if (i < present2)
			{
				if (v1.pget_down(i) != 0 && i < destination2)
					destination2 = i;
				if (v1.pget_up(i) != 0 && i < destination2)
					destination2 = i;
			}
		}

		if (elevator_state1 == 3)
		{
			if (v1.pget_down(i) != 0 && i < destination1)
				destination1 = i;
			if (v1.pget_up(i) != 0 && i < destination1)
				destination1 = i;
		}
		else if (elevator_state2 == 3)
		{
			if (v1.pget_down(i) != 0 && i < destination2)
				destination2 = i;
			if (v1.pget_up(i) != 0 && i < destination2)
				destination2 = i;
		}





	}

}

void Elevators::go_target_np(Passengers &v1)
{
	if (elevator_state1 == 2)
	{
		if (people1[0] != 0)
			destination1 = 0;
		for (int i = 0; i < 15; i++)
		{

			if (take_passengers1[i] != 0)
			{
				if (destination1 < v1.get_target(take_passengers1[i]))
					destination1 = v1.get_target(take_passengers1[i]);
			}
		}
	}
	else if (elevator_state1 == 3)
	{

		for (int i = 0; i < 15; i++)
		{
			if (people1[0] != 0)
				destination1 = 16;
			if (take_passengers1[i] != 0)
			{
				if (destination1 > v1.get_target(take_passengers1[i]))
					destination1 = v1.get_target(take_passengers1[i]);
			}
		}
	}

	//

	if (elevator_state2 == 2)
	{
		if (people2[0] != 0)
			destination2 = 0;
		for (int i = 0; i < 15; i++)
		{

			if (take_passengers2[i] != 0)
			{
				if (destination2 < v1.get_target(take_passengers2[i]))
					destination2 = v1.get_target(take_passengers2[i]);
			}
		}
	}
	else if (elevator_state2 == 3)
	{
		if (people2[0] != 0)
			destination2 = 16;
		for (int i = 0; i < 15; i++)
		{
			if (take_passengers2[i] != 0)
			{
				if (destination2 > v1.get_target(take_passengers2[i]))
					destination2 = v1.get_target(take_passengers2[i]);
			}
		}
	}
}

void Elevators::go_create_npp(Floor &v1)//�������� ����
{
	for (int i = 0; i < 9; i++)
	{
		if (elevator_state1 == 2)
		{
			if (i > present1)
			{
				if (v1.pget_up(i) != 0 && i > destination1)
					destination1 = i;
				if (v1.pget_down(i) != 0 && i > destination1)
					destination1 = i;
			}
		}
		else if (elevator_state1 == 1)
		{
			if (i > present1)
			{
				if (v1.pget_up(i) != 0 && i > destination1)
					destination1 = i;
				if (v1.pget_down(i) != 0 && i > destination1)
					destination1 = i;
			}
			else if (i < present1)
			{
				if (v1.pget_down(i) != 0 && i < destination1)
					destination1 = i;
				if (v1.pget_up(i) != 0 && i < destination1)
					destination1 = i;
			}
		}
		else if (elevator_state1 == 3)
		{
			if (i < present1)
			{
				if (v1.pget_down(i) != 0 && i < destination1)
					destination1 = i;
				if (v1.pget_up(i) != 0 && i < destination1)
					destination1 = i;
			}
		}
	}
	//
	if (1) {
		for (int i = 8; i < 17; i++)
		{
			if (elevator_state2 == 2)
			{
				if (i > present2)
				{
					if (v1.pget_up(i) != 0 && i > destination2)
						destination2 = i;
					if (v1.pget_down(i) != 0 && i > destination2)
						destination2 = i;
				}
			}
			else if (elevator_state2 == 1)
			{
				if (i > present2)
				{
					if (v1.pget_up(i) != 0 && i > destination2)
						destination2 = i;
					if (v1.pget_down(i) != 0 && i > destination2)
						destination2 = i;
				}
				else if (i < present2)
				{
					if (v1.pget_down(i) != 0 && i < destination2)
						destination2 = i;
					if (v1.pget_up(i) != 0 && i < destination2)
						destination2 = i;
				}
			}
			else if (elevator_state2 == 3 && destination2 != 8)
			{
				if (i < present2)
				{
					if (v1.pget_down(i) != 0 && i < destination2)
						destination2 = i;
					if (v1.pget_up(i) != 0 && i < destination2)
						destination2 = i;
				}
			}
		}
	}

}

void Elevators::go_target_npp(Passengers &v1)
{
	if (elevator_state1 == 2)
	{
		if (people1[0] != 0)
			destination1 = 8;
		for (int i = 0; i < 15; i++)
		{

			if (take_passengers1[i] != 1000)
			{
				if (destination1 < v1.get_target(take_passengers1[i])) {
					
					if (v1.get_target(take_passengers1[i]) > 8) {
						v1.set_intersection_target(take_passengers1[i], v1.get_target(take_passengers1[i]));// ���� �� ������ ����
						v1.set_target(take_passengers1[i], 8);//������ �ӽ� ����
						v1.set_intersection(take_passengers1[i]);// ����ī��Ʈ ����
						destination1 = 8;
					}
					else destination1 = v1.get_target(take_passengers1[i]);
				}
			}
		}
	}
	else if (elevator_state1 == 3)
	{

		for (int i = 0; i < 15; i++)
		{
			if (people1[0] != 0)
				destination1 = 0;
			if (take_passengers1[i] != 1000)
			{
				if (destination1 < v1.get_target(take_passengers1[i])) {
					
					if (v1.get_target(take_passengers1[i]) > 8) {
						v1.set_intersection_target(take_passengers1[i], v1.get_target(take_passengers1[i]));// ���� �� ������ ����
						v1.set_target(take_passengers1[i], 8);//������ �ӽ� ����
						v1.set_intersection(take_passengers1[i]);// ����ī��Ʈ ����
						destination1 = 8;
					}
					else destination1 = v1.get_target(take_passengers1[i]);
				}
			}
		}
	}

	//

	if (elevator_state2 == 2)
	{
		if (people2[0] != 0)
			destination2 = 8;
		for (int i = 0; i < 15; i++)
		{

			if (take_passengers2[i] != 1000)
			{
				if (destination2 < v1.get_target(take_passengers2[i])) {

					if (v1.get_target(take_passengers2[i]) < 8) {
						v1.set_target(take_passengers2[i], 8);
						destination2 = 8;
					}
					else destination2 = v1.get_target(take_passengers2[i]);
				}
				else if (destination2 > v1.get_target(take_passengers2[i]) && v1.get_target(take_passengers2[i]) < 8)
					v1.set_target(take_passengers2[i], 8);

			}
		}
	}
	else if (elevator_state2 == 3)
	{
		if (people2[0] != 0)
			destination2 = 16;
		for (int i = 0; i < 15; i++)
		{
			if (take_passengers2[i] != 1000)
			{
				if (destination2 > v1.get_target(take_passengers2[i])) {
					if (v1.get_target(take_passengers2[i]) < 8) {
						v1.set_intersection_target(take_passengers2[i], v1.get_target(take_passengers2[i]));// ���� �� ������ ����
						v1.set_target(take_passengers2[i], 8);//������ �ӽ� ����
						v1.set_intersection(take_passengers2[i]);// ����ī��Ʈ ����
						destination2 = 8;
					}
					else destination2 = v1.get_target(take_passengers2[i]);
				}
				else if (destination2 > v1.get_target(take_passengers2[i]) && v1.get_target(take_passengers2[i]) < 8) {
					v1.set_target(take_passengers2[i], 8);
					destination2 = 8;
				}
			}
		}
	}
}

void Elevators::take_in_out_npp(Passengers& v1, Floor& v2)
{
	for (int i = 0; i <= v1.get_person(); i++)//���������� Ÿ�ºκ�
	{
		if (present1 == v1.get_create(i))//Ÿ�°Ͱ��� ����1��
		{
			if (v1.get_intersection_target(i) > 8) v1.set_intersection(i);
			if (elevator_state1 == 1)//������ �����ΰ�� �ȿ� �մԾ��ٴ¶�!
			{
				
				if (v1.get_act(i) == 1  && v1.get_intersection(i) != 1)//�ö� �մ�~ �Ȱ���Ÿ�� �մ�
				{
					v2.minus_pget_up(present1, 1);
					take_passengers1[people1[1]] = i;//ź���� ��� 
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 2;//������ ���οö󰥻���� ���������� ���������͸� ���οö󰡴»��·ιٲ���
				}
				else if (v1.get_act(i) == 1 && v1.get_intersection(i) == 1 && v1.get_create(i)!=8) {//�ö󰡸� �����ϴ� ���
					v2.minus_pget_up(present1, 1);
					take_passengers1[people1[1]] = i;//ź���� ��� 
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 2;//������ ���οö󰥻���� ���������� ���������͸� ���οö󰡴»��·ιٲ���
				}
				else if (v1.get_act(i) == 2)//������ �մ�~
				{
					v2.minus_pget_down(present1, 1);
					take_passengers1[people1[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 3;
				}
			}
			else if (elevator_state1 == 2)//��
			{

				if (v1.get_act(i) == 1 && v1.get_create(i) != 8)//�ö󰥻���϶�
				{
					if (people1[1] < 15)//15���� ������ �� Ż������
					{
						v2.minus_pget_up(present1, 1);
						take_passengers1[people1[1]] = i;//�׻���� ������ ����
						v1.take_up(i);//�� ��� ź���·�
						v1.set_act(i);
						people1[1]++;//ź��� ����
					}
				}
				else if (v1.get_act(i) == 1 && v1.get_intersection(i) == 1) {//�ö󰡸� �����ϴ� ���
					v2.minus_pget_up(present1, 1);
					take_passengers1[people1[1]] = i;//ź���� ��� 
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					//elevator_state1 = 2;//������ ���οö󰥻���� ���������� ���������͸� ���οö󰡴»��·ιٲ���
				}
			}
			else if (elevator_state1 == 3)//�Ʒ�
			{
				if (v1.get_act(i) == 2)//�������»��
				{
					if (people1[1] < 15)
					{
						v2.minus_pget_down(present1, 1);
						take_passengers1[people1[1]] = i;
						v1.take_up(i);
						v1.set_act(i);
						people1[1]++;
					}
				}
			}
		}


		if (present2 == v1.get_create(i))//Ÿ�°Ͱ��� ����2��
		{
			if (v1.get_intersection_target(i) < 8) v1.set_intersection(i);
			if (elevator_state2 == 1)//������ �����ΰ�� �ȿ� �մԾ��ٴ¶�!
			{
				if (v1.get_act(i) == 1)//�ö� �մ�~
				{
					v2.minus_pget_up(present2, 1);
					take_passengers2[people2[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					elevator_state2 = 2;//������ ���οö󰥻���� ���������� ���������͸� ���οö󰡴»��·ιٲ���
				}
				else if (v1.get_act(i) == 2)//������ �մ�~
				{
					v2.minus_pget_down(present2, 1);
					take_passengers2[people2[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					elevator_state2 = 3;
				}
				else if (v1.get_act(i) == 2 && v1.get_intersection(i) == 1 &&v1.get_create(i) != 8) {
					v2.minus_pget_up(present2, 1);
					take_passengers1[people2[1]] = i;//ź���� ��� 
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 2;//������ ���οö󰥻���� ���������� ���������͸� ���οö󰡴»��·ιٲ���
				}
			}
			else if (elevator_state2 == 2)//��
			{
				if (v1.get_act(i) == 1)//�ö󰥻���϶�
				{
					if (people2[1] < 15)//15���� ������ �� Ż������
					{
						v2.minus_pget_up(present2, 1);
						take_passengers2[people2[1]] = i;//�׻���� ������ ����
						v1.take_up(i);//�� ��� ź���·�
						v1.set_act(i);
						people2[1]++;//ź��� ����

					}
				}
			}

			else if (elevator_state2 == 3)//�Ʒ�
			{
				if (v1.get_act(i) == 2)//�������»��
				{
					if (people2[1] < 15)
					{
						v2.minus_pget_down(present2, 1);
						take_passengers2[people2[1]] = i;
						v1.set_act(i);
						v1.take_up(i);
						people2[1]++;

					}
				}
				else if (v1.get_act(i) == 2 && v1.get_intersection(i) == 1) {//�ö󰡸� �����ϴ� ���
					v2.minus_pget_down(present2, 1);
					take_passengers1[people2[1]] = i;//ź���� ��� 
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					
				}
			}
		}
	}
	//������ �κ�
	people1[2] = people1[1];//people[2]�� �������� �մԼ��� �ǵ���
	people2[2] = people2[1];

	for (int i = 0; i < 15; i++)
	{//����1
		if (present1 == v1.get_target(take_passengers1[i]) && v1.get_take(take_passengers1[i]) == 1)// ���� Ÿ���ִ»���� �������� �������� ������
		{
			if (v1.get_intersection(take_passengers1[i]) == 1 && present1 == 8) {//����Ÿ�� �����
				v2.plus_pget_up(8);//���� �������
				v2.plus_tget_up(v1.get_intersection_target(take_passengers1[i]));//���� �ö� ��� ����
				v1.take_down(take_passengers1[i]);
				v1.set_create(take_passengers1[i], 8);
				v1.set_act_1(take_passengers1[i]);
				v1.set_target(take_passengers1[i], v1.get_intersection_target(take_passengers1[i]));
				people1[2]--;//�ȿ� �������
				take_passengers1[i] = 1000;
			}
			else {//�Ȱ���Ÿ�� �����
				v1.take_down(take_passengers1[i]);//���������ŷ� ����
				people1[2]--;//�ȿ� �������
				take_passengers1[i] = 1000;
			}
		}

		//����2
		if (present2 == v1.get_target(take_passengers2[i]) && v1.get_take(take_passengers2[i]) == 1)
		{
			/*if (present2 != v1.get_intersection_target(take_passengers2[i]))
				;
			else {
				v1.take_down(take_passengers2[i]);
				people2[2]--;
				take_passengers2[i] = 1000;
			}*/
			if (v1.get_intersection(take_passengers2[i]) == 1 && present2 == 8) {//����Ÿ�� �����
				v2.plus_pget_down(8);//���� �������
				v2.plus_tget_down(v1.get_intersection_target(take_passengers2[i]));//���� �ö� ��� ����
				v1.take_down(take_passengers2[i]);
				v1.set_create(take_passengers2[i], 8);
				v1.set_act_2(take_passengers2[i]);
				v1.set_target(take_passengers2[i], v1.get_intersection_target(take_passengers2[i]));
				people2[2]--;//�ȿ� �������
				take_passengers2[i] = 1000;
			}
			else {
				v1.take_down(take_passengers2[i]);
				people2[2]--;
				take_passengers2[i] = 1000;
			}
		}


	}

	move_arrange(take_passengers1,v1);
	move_arrange(take_passengers2,v1);

}

void Elevators::go_create_oe(Floor &v1)//�������� ����
{
	for (int i = 0; i < 9; i++)
	{
		if (elevator_state1 == 2)
		{
			if (2 * i > present1)
			{
				if (v1.pget_up(2 * i) != 0 && 2 * i > destination1)
					destination1 = 2 * i;
				if (v1.pget_down(2 * i) != 0 && 2 * i > destination1)
					destination1 = 2 * i;
			}
		}
		else if (elevator_state1 == 1)
		{
			if (2 * i > present1)
			{
				if (v1.pget_up(2 * i) != 0 && 2 * i > destination1)
					destination1 = 2 * i;
				if (v1.pget_down(2 * i) != 0 && 2 * i > destination1)
					destination1 = 2 * i;
			}
			else if (2 * i < present1)
			{
				if (v1.pget_down(2 * i) != 0 && 2 * i < destination1)
					destination1 = 2 * i;
				if (v1.pget_up(2 * i) != 0 && 2 * i < destination1)
					destination1 = 2 * i;
			}
		}
		else if (elevator_state1 == 3)
		{
			if (2 * i < present1)
			{
				if (v1.pget_down(2 * i) != 0 && 2 * i < destination1)
					destination1 = 2 * i;
				if (v1.pget_up(2 * i) != 0 && i < destination1)
					destination1 = 2 * i;
			}
		}
	}

	///
	for (int i = 1; i < 9; i++)
	{
		if (elevator_state2 == 2)
		{
			if (2 * i - 1 > present2)
			{
				if (v1.pget_up(2 * i - 1) != 0 && 2 * i - 1 > destination2)
					destination2 = 2 * i - 1;
				if (v1.pget_down(2 * i - 1) != 0 && 2 * i - 1 > destination2)
					destination2 = 2 * i - 1;
			}
		}
		else if (elevator_state2 == 1)
		{
			if (2 * i - 1 > present2)
			{
				if (v1.pget_up(2 * i - 1) != 0 && 2 * i - 1 > destination2)
					destination2 = 2 * i - 1;
				if (v1.pget_down(2 * i - 1) != 0 && 2 * i - 1 > destination2)
					destination2 = 2 * i - 1;
			}
			else if (2 * i - 1 < present2)
			{
				if (v1.pget_down(2 * i - 1) != 0 && 2 * i - 1 < destination2)
					destination2 = 2 * i - 1;
				if (v1.pget_up(2 * i - 1) != 0 && 2 * i - 1 < destination2)
					destination2 = 2 * i - 1;
			}
		}
		else if (elevator_state2 == 3)
		{
			if (2 * i - 1 < present2)
			{
				if (v1.pget_down(2 * i - 1) != 0 && 2 * i - 1 < destination2)
					destination2 = 2 * i - 1;
				if (v1.pget_up(2 * i - 1) != 0 && 2 * i - 1 < destination2)
					destination2 = 2 * i - 1;
			}
		}
	}

}


void Elevators::take_in_out_oe(Passengers &v1, Floor &v2)
{
	for (int i = 0; i <= v1.get_person(); i++)//���������� Ÿ�ºκ�
	{



		if (present1 == v1.get_create(i) && (present1 == 0 || present1 == 2 || present1 == 4 || present1 == 6 || present1 == 8 || present1 == 10 || present1 == 12 || present1 == 14 || present1 == 16))//Ÿ�°Ͱ��� ����1��
		{
			if (elevator_state1 == 1)//������ �����ΰ�� �ȿ� �մԾ��ٴ¶�!
			{
				if (v1.get_act(i) == 1)//�ö� �մ�~
				{
					v2.minus_pget_up(present1, 1);
					take_passengers1[people1[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					destination1 = v1.get_target(i);
					elevator_state1 = 2;//������ ���οö󰥻���� ���������� ���������͸� ���οö󰡴»��·ιٲ���
				}
				else if (v1.get_act(i) == 2)//������ �մ�~
				{
					v2.minus_pget_down(present1, 1);
					take_passengers1[people1[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					destination1 = v1.get_target(i);
					elevator_state1 = 3;
				}
			}
			else if (elevator_state1 == 2)//��
			{
				if (v1.get_act(i) == 1)//�ö󰥻���϶�
				{
					if (people1[1] < 15)//15���� ������ �� Ż������
					{
						v2.minus_pget_up(present1, 1);
						take_passengers1[people1[1]] = i;//�׻���� ������ ����
						v1.take_up(i);//�� ��� ź���·�
						v1.set_act(i);
						people1[1]++;//ź��� ����
						if (v1.get_target(i) > destination1)
							destination1 = v1.get_target(i);//�������� ��ũ�� �ٲ���
					}
				}
			}
			else if (elevator_state1 == 3)//�Ʒ�
			{
				if (v1.get_act(i) == 2)//�������»��
				{
					if (people1[1] < 15)
					{
						v2.minus_pget_down(present1, 1);
						take_passengers1[people1[1]] = i;
						v1.take_up(i);
						v1.set_act(i);
						people1[1]++;
						if (v1.get_target(i) < destination1)
							destination1 = v1.get_target(i);//�������� �������� �ٲ���
					}
				}
			}
		}


		if (present2 == v1.get_create(i) && (present2 == 1 || present2 == 3 || present2 == 5 || present2 == 7 || present2 == 9 || present2 == 11 || present2 == 13 || present2 == 15))//Ÿ�°Ͱ��� ����2��
		{
			if (elevator_state2 == 1)//������ �����ΰ�� �ȿ� �մԾ��ٴ¶�!
			{
				if (v1.get_act(i) == 1)//�ö� �մ�~
				{
					v2.minus_pget_up(present2, 1);
					take_passengers2[people2[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					destination2 = v1.get_target(i);
					elevator_state2 = 2;//������ ���οö󰥻���� ���������� ���������͸� ���οö󰡴»��·ιٲ���
				}
				else if (v1.get_act(i) == 2)//������ �մ�~
				{
					v2.minus_pget_down(present2, 1);
					take_passengers2[people2[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					destination2 = v1.get_target(i);
					elevator_state2 = 3;
				}
			}
			else if (elevator_state2 == 2)//��
			{
				if (v1.get_act(i) == 1)//�ö󰥻���϶�
				{
					if (people2[1] < 15)//15���� ������ �� Ż������
					{
						v2.minus_pget_up(present2, 1);
						take_passengers2[people2[1]] = i;//�׻���� ������ ����
						v1.take_up(i);//�� ��� ź���·�
						v1.set_act(i);
						people2[1]++;//ź��� ����
						if (v1.get_target(i) > destination2)
							destination2 = v1.get_target(i);//�������� ��ũ�� �ٲ���
					}
				}
			}

			else if (elevator_state2 == 3)//�Ʒ�
			{
				if (v1.get_act(i) == 2)//�������»��
				{
					if (people2[1] < 15)
					{
						v2.minus_pget_down(present2, 1);
						take_passengers2[people2[1]] = i;
						v1.set_act(i);
						v1.take_up(i);
						people2[1]++;
						if (v1.get_target(i) < destination1)
							destination1 = v1.get_target(i);//�������� �������� �ٲ���
					}
				}
			}
		}
	}
	//������ �κ�
	people1[2] = people1[1];//people[2]�� �������� �մԼ��� �ǵ���
	people2[2] = people2[1];

	for (int i = 0; i < 15; i++)
	{//����1
		if (present1 == v1.get_target(take_passengers1[i]) && v1.get_take(take_passengers1[i]) == 1)// ���� Ÿ���ִ»���� �������� �������� ������
		{
			v1.take_down(take_passengers1[i]);//���������ŷ� ����
			people1[2]--;//�ȿ� �������
			take_passengers1[i] = 0;

		}

		//����2
		if (present2 == v1.get_target(take_passengers2[i]) && v1.get_take(take_passengers2[i]) == 1)
		{
			v1.take_down(take_passengers2[i]);
			people2[2]--;
			take_passengers2[i] = 0;

		}


	}

	move_arrange(take_passengers1,v1);
	move_arrange(take_passengers2,v1);
}

void Elevators::go_go()//�������� ����2~15�� �͸�����
{
	if (destination1 == 16)
	{
		if (present1 == 16)
			destination1 = 0;
	}
	else if (destination1 == 0)
	{
		if (present1 == 0)
			destination1 = 16;
	}
	////
	if (destination2 == 16)
	{
		if (present2 == 16)
			destination2 = 0;
	}
	else if (destination2 == 0)
	{
		if (present2 == 0)
			destination2 = 16;
	}



}


void Elevators::take_in_outFIFO(Passengers& v1, Floor& v2)
{
	for (int i = 0; i <= v1.get_person(); i++)//���������� Ÿ�ºκ�
	{



		if (present1 == v1.get_create(i))//Ÿ�°Ͱ��� ����1��
		{
			if (elevator_state1 == 1)//������ �����ΰ�� �ȿ� �մԾ��ٴ¶�!
			{
				if (v1.get_act(i) == 1)//�ö� �մ�~
				{
					v2.minus_pget_up(present1, 1);
					take_passengers1[people1[1]] = i;//ź���� ��� 
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 2;//������ ���οö󰥻���� ���������� ���������͸� ���οö󰡴»��·ιٲ���
				}
				else if (v1.get_act(i) == 2)//������ �մ�~
				{
					v2.minus_pget_down(present1, 1);
					take_passengers1[people1[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 3;
				}
			}
			else if (elevator_state1 == 2)//��
			{
				if (v1.get_act(i) == 1)//�ö󰥻���϶�
				{
					if (people1[1] < 1)//15���� ������ �� Ż������
					{
						v2.minus_pget_up(present1, 1);
						take_passengers1[people1[1]] = i;//�׻���� ������ ����
						v1.take_up(i);//�� ��� ź���·�
						v1.set_act(i);
						people1[1]++;//ź��� ����
					}
				}
			}
			else if (elevator_state1 == 3)//�Ʒ�
			{
				if (v1.get_act(i) == 2)//�������»��
				{
					if (people1[1] < 1)
					{
						v2.minus_pget_down(present1, 1);
						take_passengers1[people1[1]] = i;
						v1.take_up(i);
						v1.set_act(i);
						people1[1]++;
					}
				}
			}
		}


		if (present2 == v1.get_create(i))//Ÿ�°Ͱ��� ����2��
		{
			if (elevator_state2 == 1)//������ �����ΰ�� �ȿ� �մԾ��ٴ¶�!
			{
				if (v1.get_act(i) == 1)//�ö� �մ�~
				{
					v2.minus_pget_up(present2, 1);
					take_passengers2[people2[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					elevator_state2 = 2;//������ ���οö󰥻���� ���������� ���������͸� ���οö󰡴»��·ιٲ���
				}
				else if (v1.get_act(i) == 2)//������ �մ�~
				{
					v2.minus_pget_down(present2, 1);
					take_passengers2[people2[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					elevator_state2 = 3;
				}
			}
			else if (elevator_state2 == 2)//��
			{
				if (v1.get_act(i) == 1)//�ö󰥻���϶�
				{
					if (people2[1] < 15)//15���� ������ �� Ż������
					{
						v2.minus_pget_up(present2, 1);
						take_passengers2[people2[1]] = i;//�׻���� ������ ����
						v1.take_up(i);//�� ��� ź���·�
						v1.set_act(i);
						people2[1]++;//ź��� ����

					}
				}
			}

			else if (elevator_state2 == 3)//�Ʒ�
			{
				if (v1.get_act(i) == 2)//�������»��
				{
					if (people2[1] < 15)
					{
						v2.minus_pget_down(present2, 1);
						take_passengers2[people2[1]] = i;
						v1.set_act(i);
						v1.take_up(i);
						people2[1]++;

					}
				}
			}
		}
	}
	//������ �κ�
	people1[2] = people1[1];//people[2]�� �������� �մԼ��� �ǵ���
	people2[2] = people2[1];

	for (int i = 0; i < 15; i++)
	{//����1
		if (present1 == v1.get_target(take_passengers1[i]) && v1.get_take(take_passengers1[i]) == 1)// ���� Ÿ���ִ»���� �������� �������� ������
		{
			v1.take_down(take_passengers1[i]);//���������ŷ� ����
			people1[2]--;//�ȿ� �������
			take_passengers1[i] = 0;

		}

		//����2
		if (present2 == v1.get_target(take_passengers2[i]) && v1.get_take(take_passengers2[i]) == 1)
		{
			v1.take_down(take_passengers2[i]);
			people2[2]--;
			take_passengers2[i] = 0;

		}


	}

	move_arrange(take_passengers1,v1);
	move_arrange(take_passengers2,v1);
}