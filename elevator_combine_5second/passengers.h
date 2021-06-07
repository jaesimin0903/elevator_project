#pragma once
#include <vector>
#include <algorithm>

class Passengers {
private:
	int create[1001];//������
	int target[1001];//������
	int act[1001];//0.�Ҹ��&�����޼��� 1.�ö󰥰��� 2.����������(����ġ�� �����ص���)
	int take[1001];//���� Ÿ������ ��Ÿ������(1/0)
	int time[1001];//�������ִ� �ð�
	int intersection[1001];
	int intersection_target[1001];
	int person;//���ݱ��� ������ �����
	int max = 0;
	//vector<int> maxtime;
public:
	Passengers()//�°��� �ʱ���� ����
	{
		for (int i = 0; i < 1001; i++)
		{
			create[i] = 0;
			target[i] = 0;
			act[i] = 0;
			take[i] = 0;
			time[i] = 0;
			intersection[i] = 0;
			intersection_target[i] = 0;
		}
		person = 0;
	}
	~Passengers() {  };

	int get_create(int a)//create �� ��ȯ
	{
		return create[a];
	}
	int get_target(int a)//target �� ��ȯ
	{
		return target[a];
	}
	int get_act(int a)//act �� ��ȯ
	{
		return act[a];
	}
	int get_take(int a)
	{
		return take[a];
	}
	int get_person()//���ݱ��� ������ �°��� ��ȯ
	{
		return person;
	}
	int get_intersection(int a) {
		return intersection[a];
	}
	int get_intersection_target(int a) {
		return intersection_target[a];
	}
	void take_up(int a)
	{
		take[a] = 1;
	}
	void take_down(int a)
	{
		take[a] = 0;
	}
	void set_act(int a)
	{
		act[a] = 0;
	}
	void set_act_1(int a)
	{
		act[a] = 1;
	}void set_act_2(int a)
	{
		act[a] = 2;
	}
	void set_create(int a, int b) {
		create[a] = b;
	}
	void set_target(int a,int b)
	{
		target[a] = b;
	}
	void set_intersection(int a) {
		intersection[a] = 1;
	}
	void set_intersection_target(int a, int b) {
		intersection_target[a] = b;
	}
	void Produce_passenger(Floor &v1);
	void time_flow();
	void produce_choose(Floor &v1);
	int sleep_time();

	void Produce_passenger_oe(Floor &v1);
	void produce_choose_oe(Floor &v1);
};

void Passengers::Produce_passenger(Floor &v1)//�°�����&private������
{
	if (person < 999) {
		++person;

		create[person] = rand() % 16; //0~16�̱�
		target[person] = rand() % 16;
		while (1)
		{
			if (create[person] == target[person])
				target[person] = rand() % 16;
			else
				break;
		}

		if (create[person] < target[person])//�ൿ������ 
		{
			act[person] = 1;//!!�̶� person���� create���� floor���� �������ָ�?
			v1.plus_pget_up(create[person]);
			v1.plus_tget_up(target[person]);
		}
		else if (create[person] > target[person])
		{
			act[person] = 2;
			v1.plus_pget_down(create[person]);
			v1.plus_tget_down(target[person]);
		}
	}
}

void Passengers::time_flow()
{
	for (int i = 0; i < person + 1; i++)
		time[i] += 5;
}

void Passengers::produce_choose(Floor &v1)
{
	if (person < 999) {
		++person;
		int a, b;
		while (1)
		{
			cout << "�߰��� �°��� ������,�������� �Է����ּ���" << endl;

			cin >> a >> b;
			if (a == b)
				cout << "�������� �Է��ϼ̽��ϴ� �ٽ��Է����ּ���" << endl;
			else
				break;
		}
		create[person] = a;
		target[person] = b;

		if (create[person] < target[person])//�ൿ������ 
		{
			act[person] = 1;//!!�̶� person���� create���� floor���� �������ָ�?
			v1.plus_pget_up(create[person]);
			v1.plus_tget_up(target[person]);
		}
		else if (create[person] > target[person])
		{
			act[person] = 2;
			v1.plus_pget_down(create[person]);
			v1.plus_tget_down(target[person]);
		}
		else if (create[person] > intersection_target[person]) {
			act[person] = 2;
 		}
		else if (create[person] < intersection_target[person]) {
			act[person] = 1;
		}
	}
}

int Passengers::sleep_time()
{
	
	for (int i = 1; i < person + 1; i++)
	{
		if (act[i] == 0 && take[i] == 0)
			;
		else
		{
			if (max >= time[i])
				;
			else if (max < time[i]) {
				max = time[i];
			}
		}
	}
	return max;
}


void Passengers::Produce_passenger_oe(Floor &v1)//�°�����&private������
{
	if (person < 999) {
		++person;
		int x = rand() % 2;
		if (rand() % 2 == 0)//¦��
		{
			create[person] = (rand() % 9) * 2;
			target[person] = (rand() % 9) * 2;
			while (1)
			{
				if (create[person] == target[person])
					target[person] = (rand() % 9) * 2;
				else
					break;
			}
		}
		else//Ȧ��
		{
			create[person] = (rand() % 8 + 1) * 2 - 1;
			target[person] = (rand() % 8 + 1) * 2 - 1;
			while (1)
			{
				if (create[person] == target[person])
					target[person] = (rand() % 8 + 1) * 2 - 1;
				else
					break;
			}
		}
		if (create[person] < target[person])//�ൿ������ 
		{
			act[person] = 1;//!!�̶� person���� create���� floor���� �������ָ�?
			v1.plus_pget_up(create[person]);
			v1.plus_tget_up(target[person]);
		}
		else if (create[person] > target[person])
		{
			act[person] = 2;
			v1.plus_pget_down(create[person]);
			v1.plus_tget_down(target[person]);
		}
	}
}

void Passengers::produce_choose_oe(Floor &v1)
{
	++person;
	int a, b;
	while (1)
	{
		cout << "�߰��� �°��� ������,�������� �Է����ּ���" << endl;

		cin >> a >> b;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (a == b || (a == 2 * i || b == 2 * j - 1) || (a == 2 * i - 1 || b == 2 * i))
					cout << "������&Ȧ¦�ٸ��� �Է��ϼ̽��ϴ� �ٽ��Է����ּ���" << endl;
				else
					break;
			}
		}
	}
	create[person] = a;
	target[person] = b;

	if (create[person] < target[person])//�ൿ������ 
	{
		act[person] = 1;//!!�̶� person���� create���� floor���� �������ָ�?
		v1.plus_pget_up(create[person]);
		v1.plus_tget_up(target[person]);
	}
	else if (create[person]>target[person])
	{
		act[person] = 2;
		v1.plus_pget_down(create[person]);
		v1.plus_tget_down(target[person]);
	}
}
