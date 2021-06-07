#pragma once
#include <vector>
#include <algorithm>

class Passengers {
private:
	int create[1001];//생성층
	int target[1001];//목적층
	int act[1001];//0.소멸시&목적달성시 1.올라갈건지 2.내려갈건지(스위치라 생각해도댐)
	int take[1001];//엘베 타고있음 안타고있음(1/0)
	int time[1001];//생성되있던 시간
	int intersection[1001];
	int intersection_target[1001];
	int person;//지금까지 생성된 사람수
	int max = 0;
	//vector<int> maxtime;
public:
	Passengers()//승객들 초기상태 설정
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

	int get_create(int a)//create 값 반환
	{
		return create[a];
	}
	int get_target(int a)//target 값 반환
	{
		return target[a];
	}
	int get_act(int a)//act 값 반환
	{
		return act[a];
	}
	int get_take(int a)
	{
		return take[a];
	}
	int get_person()//지금까지 생성된 승객수 반환
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

void Passengers::Produce_passenger(Floor &v1)//승객만듬&private값설정
{
	if (person < 999) {
		++person;

		create[person] = rand() % 16; //0~16뽑기
		target[person] = rand() % 16;
		while (1)
		{
			if (create[person] == target[person])
				target[person] = rand() % 16;
			else
				break;
		}

		if (create[person] < target[person])//행동정해줌 
		{
			act[person] = 1;//!!이때 person값과 create값을 floor에서 저장해주면?
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
			cout << "추가할 승객의 생성지,목적지를 입력해주세요" << endl;

			cin >> a >> b;
			if (a == b)
				cout << "같은수를 입력하셨습니다 다시입력해주세요" << endl;
			else
				break;
		}
		create[person] = a;
		target[person] = b;

		if (create[person] < target[person])//행동정해줌 
		{
			act[person] = 1;//!!이때 person값과 create값을 floor에서 저장해주면?
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


void Passengers::Produce_passenger_oe(Floor &v1)//승객만듬&private값설정
{
	if (person < 999) {
		++person;
		int x = rand() % 2;
		if (rand() % 2 == 0)//짝수
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
		else//홀수
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
		if (create[person] < target[person])//행동정해줌 
		{
			act[person] = 1;//!!이때 person값과 create값을 floor에서 저장해주면?
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
		cout << "추가할 승객의 생성지,목적지를 입력해주세요" << endl;

		cin >> a >> b;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (a == b || (a == 2 * i || b == 2 * j - 1) || (a == 2 * i - 1 || b == 2 * i))
					cout << "같은수&홀짝다르게 입력하셨습니다 다시입력해주세요" << endl;
				else
					break;
			}
		}
	}
	create[person] = a;
	target[person] = b;

	if (create[person] < target[person])//행동정해줌 
	{
		act[person] = 1;//!!이때 person값과 create값을 floor에서 저장해주면?
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
