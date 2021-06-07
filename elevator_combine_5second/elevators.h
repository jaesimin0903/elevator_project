#pragma once
#include<vector>
#include<algorithm> 


void move_arrange(vector<int> &a,Passengers &v1);//배열을 <<쪽으로 정리해주는 역할을해주는 함수

using namespace std;
class Elevators {
private:
	int present1;//현재 층
	int present2;
	int destination1;//목적층
	int destination2;
	int door_situation1;//문상태(문열림,닫힘)=(1/0)
	int door_situation2;
	int elevator_state1;//1.목적지없음 2.올라가는중 3.내려가는중
	int elevator_state2;
	int people1[3];//[0]. 이전에 있던사람수, [1]. 탄후 바뀐 사람수, [2] 내린후 바뀐 사람수
	int people2[3];
	vector<int> take_passengers1;
	vector<int> take_passengers2;
	int take_passengerFIFO1[15];
	int timeStamp;
public:
	Elevators(int a = 0, int b = 0, int c = 16, int d = 16) :present1(a), destination1(b), present2(c), destination2(d)
	{//엘리베이터 초기상태 설정
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
	void Elevator_state();//엘리베이터 상태설정
	void Elevator_move_take_in_out(Passengers &v1, Floor &v2);//엘리베이터 행동, 목적지설정
	void go_create_n(Floor &v1);//생성지로 ㄱㄱ
	void go_target_n(Passengers &v1);//엘리베이터탄사람 목적지로
	void take_in_out(Passengers &v1, Floor &v2);//엘리베이터 타고내림

	void go_create_np(Floor &v1);//생성지로 ㄱㄱ
	void go_target_np(Passengers &v1);//엘리베이터탄사람 목적지로

	void go_create_npp(Floor &v1);//생성지로 ㄱㄱ
	void go_target_npp(Passengers &v1);//엘리베이터탄사람 목적지로
	void take_in_out_npp(Passengers& v1, Floor& v2);

	void go_create_oe(Floor &v1);
	void take_in_out_oe(Passengers &v1, Floor &v2);

	void go_go();

	void take_in_outFIFO(Passengers& v1, Floor& v2);
};

void move_arrange(vector<int>& v, Passengers& v1)//배열을 <<쪽으로 정리해주는 역할을해주는 함수
{
	sort(v.begin(), v.end());
}

void Elevators::Elevator_state()//엘리베이터 상태설정
{
	if (destination1 > present1)//엘베1상태
		elevator_state1 = 2;
	else if (destination1 < present1)
		elevator_state1 = 3;
	else if (destination1 == present1)
		elevator_state1 = 1;


	if (destination2 > present2)//엘베2상태
		elevator_state2 = 2;
	else if (destination2 < present2)
		elevator_state2 = 3;
	else if (destination2 == present2)
		elevator_state2 = 1;
}

void Elevators::Elevator_move_take_in_out(Passengers &v1, Floor &v2)//엘리베이터 행동, 목적지설정
{

	if (elevator_state1 == 1)//목적지없음
	{
		//timeStamp++;
	}
	else if (elevator_state1 == 2)//올라가는중
	{
		if (people1[0] == people1[1] && people1[1] == people1[2])//손님없다면
		{
			present1++;
			timeStamp++;
		}
		else//손님이 있다면
		{
			door_situation1 = 1;//문열어줌
			timeStamp++;

		}

	}
	else if (elevator_state1 == 3)//내려가는중
	{
		if (people1[0] == people1[1] && people1[1] == people1[2])//손님없다면
		{
			present1--;
			timeStamp++;
		}
		else//손님이 있다면
		{
			door_situation1 = 1;//문열어줌
			timeStamp++;

		}
	}

	//엘베2
	if (elevator_state2 == 1)//목적지없음
	{
		//timeStamp++;
	}
	else if (elevator_state2 == 2)//올라가는중
	{
		if (people2[0] == people2[1] && people2[1] == people2[2])//손님없다면
		{
			present2++;
			timeStamp++;
		}
		else//손님이 있다면
		{
			door_situation2 = 1;//문열어줌
			timeStamp++;

		}

	}
	else if (elevator_state2 == 3)//내려가는중
	{
		if (people2[0] == people2[1] && people2[1] == people2[2])//손님없다면
		{
			present2--;
			timeStamp++;
		}
		else//손님이 있다면
		{
			door_situation2 = 1;//문열어줌
			timeStamp++;

		}
	}

	people1[0] = people1[2];
	people1[1] = people1[2];
	people2[0] = people2[2];
	people2[1] = people2[2];




}

void Elevators::go_create_n(Floor &v1)//생성지로 ㄱㄱ
{
	for (int i = 0; i < 17; i++)
	{
		if (elevator_state1 == 2)///up
		{
			if (i > present1)//엘리베이터 현재 위치보다 크다면
			{
				if (v1.pget_up(i) != 0 && i > destination1)// 그층의 올라갈사람이 있고 목적지보다 높이 있다면
					destination1 = i;
				if (v1.pget_down(i) != 0 && i > destination1)// 그층의 내려갈사람이 있고 목적지보다 높이 있다면
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
		if (people1[0] != 0)//이전에 있던 사람 수 0 이 아니라면
			destination1 = 0;//도착지 초기화
		for (int i = 0; i < 15; i++)
		{

			if (take_passengers1[i] != 0)//엘베에 사람이 타있다면
			{
				if (destination1 < v1.get_target(take_passengers1[i]))//엘리베이터의 도착지보다 타고있는 사람의 목적지가 크다면
					destination1 = v1.get_target(take_passengers1[i]);//목적지 변경
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

	for (int i = 0; i <= v1.get_person(); i++)//엘리베이터 타는부분
	{



		if (present1 == v1.get_create(i))//타는것관련 엘베1옴
		{
			if (elevator_state1 == 1 && people1[1] < 15)//도착후 정지인경우 안에 손님없다는뜻!
			{
				if (v1.get_act(i) == 1)//올라갈 손님~
				{
					v2.minus_pget_up(present1, 1);
					take_passengers1[people1[1]] = i;//탄순서 대로 
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 2;//먼저온 위로올라갈사람이 먼저탔으니 엘리베이터를 위로올라가는상태로바꿔줌
				}
				else if (v1.get_act(i) == 2)//내려갈 손님~
				{
					v2.minus_pget_down(present1, 1);
					take_passengers1[people1[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 3;
				}
			}
			else if (elevator_state1 == 2)//위
			{
				if (v1.get_act(i) == 1)//올라갈사람일때
				{
					if (people1[1] < 15)//15명보다 적을때 더 탈수있음
					{
						v2.minus_pget_up(present1, 1);
						take_passengers1[people1[1]] = i;//그사람이 누군지 저장
						v1.take_up(i);//그 사람 탄상태로
						v1.set_act(i);
						people1[1]++;//탄사람 증가
					}
				}
			}
			else if (elevator_state1 == 3)//아래
			{
				if (v1.get_act(i) == 2)//내려가는사람
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


		if (present2 == v1.get_create(i))//타는것관련 엘베2옴
		{
			if (elevator_state2 == 1)//도착후 정지인경우 안에 손님없다는뜻!
			{
				if (v1.get_act(i) == 1)//올라갈 손님~
				{
					v2.minus_pget_up(present2, 1);
					take_passengers2[people2[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					elevator_state2 = 2;//먼저온 위로올라갈사람이 먼저탔으니 엘리베이터를 위로올라가는상태로바꿔줌
				}
				else if (v1.get_act(i) == 2)//내려갈 손님~
				{
					v2.minus_pget_down(present2, 1);
					take_passengers2[people2[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					elevator_state2 = 3;
				}
			}
			else if (elevator_state2 == 2)//위
			{
				if (v1.get_act(i) == 1)//올라갈사람일때
				{
					if (people2[1] < 15)//15명보다 적을때 더 탈수있음
					{
						v2.minus_pget_up(present2, 1);
						take_passengers2[people2[1]] = i;//그사람이 누군지 저장
						v1.take_up(i);//그 사람 탄상태로
						v1.set_act(i);
						people2[1]++;//탄사람 증가

					}
				}
			}

			else if (elevator_state2 == 3)//아래
			{
				if (v1.get_act(i) == 2)//내려가는사람
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
	//내리는 부분
	people1[2] = people1[1];//people[2]가 최종적인 손님수가 되도록
	people2[2] = people2[1];

	for (int i = 0; i < 15; i++)
	{//엘베1
		if (present1 == v1.get_target(take_passengers1[i]) && v1.get_take(take_passengers1[i]) == 1)// 만약 타고있는사람의 목적지와 현재층이 같을때
		{
			v1.take_down(take_passengers1[i]);//엘베내린거로 해줌
			people1[2]--;//안에 사람줄음
			take_passengers1[i] = 1000;

		}

		//엘베2
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

void Elevators::go_create_np(Floor &v1)//생성지로 ㄱㄱ
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

void Elevators::go_create_npp(Floor &v1)//생성지로 ㄱㄱ
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
						v1.set_intersection_target(take_passengers1[i], v1.get_target(take_passengers1[i]));// 교차 후 도착지 설정
						v1.set_target(take_passengers1[i], 8);//교차지 임시 설정
						v1.set_intersection(take_passengers1[i]);// 교차카운트 생성
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
						v1.set_intersection_target(take_passengers1[i], v1.get_target(take_passengers1[i]));// 교차 후 도착지 설정
						v1.set_target(take_passengers1[i], 8);//교차지 임시 설정
						v1.set_intersection(take_passengers1[i]);// 교차카운트 생성
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
						v1.set_intersection_target(take_passengers2[i], v1.get_target(take_passengers2[i]));// 교차 후 도착지 설정
						v1.set_target(take_passengers2[i], 8);//교차지 임시 설정
						v1.set_intersection(take_passengers2[i]);// 교차카운트 생성
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
	for (int i = 0; i <= v1.get_person(); i++)//엘리베이터 타는부분
	{
		if (present1 == v1.get_create(i))//타는것관련 엘베1옴
		{
			if (v1.get_intersection_target(i) > 8) v1.set_intersection(i);
			if (elevator_state1 == 1)//도착후 정지인경우 안에 손님없다는뜻!
			{
				
				if (v1.get_act(i) == 1  && v1.get_intersection(i) != 1)//올라갈 손님~ 안갈아타는 손님
				{
					v2.minus_pget_up(present1, 1);
					take_passengers1[people1[1]] = i;//탄순서 대로 
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 2;//먼저온 위로올라갈사람이 먼저탔으니 엘리베이터를 위로올라가는상태로바꿔줌
				}
				else if (v1.get_act(i) == 1 && v1.get_intersection(i) == 1 && v1.get_create(i)!=8) {//올라가며 교차하는 사람
					v2.minus_pget_up(present1, 1);
					take_passengers1[people1[1]] = i;//탄순서 대로 
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 2;//먼저온 위로올라갈사람이 먼저탔으니 엘리베이터를 위로올라가는상태로바꿔줌
				}
				else if (v1.get_act(i) == 2)//내려갈 손님~
				{
					v2.minus_pget_down(present1, 1);
					take_passengers1[people1[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 3;
				}
			}
			else if (elevator_state1 == 2)//위
			{

				if (v1.get_act(i) == 1 && v1.get_create(i) != 8)//올라갈사람일때
				{
					if (people1[1] < 15)//15명보다 적을때 더 탈수있음
					{
						v2.minus_pget_up(present1, 1);
						take_passengers1[people1[1]] = i;//그사람이 누군지 저장
						v1.take_up(i);//그 사람 탄상태로
						v1.set_act(i);
						people1[1]++;//탄사람 증가
					}
				}
				else if (v1.get_act(i) == 1 && v1.get_intersection(i) == 1) {//올라가며 교차하는 사람
					v2.minus_pget_up(present1, 1);
					take_passengers1[people1[1]] = i;//탄순서 대로 
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					//elevator_state1 = 2;//먼저온 위로올라갈사람이 먼저탔으니 엘리베이터를 위로올라가는상태로바꿔줌
				}
			}
			else if (elevator_state1 == 3)//아래
			{
				if (v1.get_act(i) == 2)//내려가는사람
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


		if (present2 == v1.get_create(i))//타는것관련 엘베2옴
		{
			if (v1.get_intersection_target(i) < 8) v1.set_intersection(i);
			if (elevator_state2 == 1)//도착후 정지인경우 안에 손님없다는뜻!
			{
				if (v1.get_act(i) == 1)//올라갈 손님~
				{
					v2.minus_pget_up(present2, 1);
					take_passengers2[people2[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					elevator_state2 = 2;//먼저온 위로올라갈사람이 먼저탔으니 엘리베이터를 위로올라가는상태로바꿔줌
				}
				else if (v1.get_act(i) == 2)//내려갈 손님~
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
					take_passengers1[people2[1]] = i;//탄순서 대로 
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 2;//먼저온 위로올라갈사람이 먼저탔으니 엘리베이터를 위로올라가는상태로바꿔줌
				}
			}
			else if (elevator_state2 == 2)//위
			{
				if (v1.get_act(i) == 1)//올라갈사람일때
				{
					if (people2[1] < 15)//15명보다 적을때 더 탈수있음
					{
						v2.minus_pget_up(present2, 1);
						take_passengers2[people2[1]] = i;//그사람이 누군지 저장
						v1.take_up(i);//그 사람 탄상태로
						v1.set_act(i);
						people2[1]++;//탄사람 증가

					}
				}
			}

			else if (elevator_state2 == 3)//아래
			{
				if (v1.get_act(i) == 2)//내려가는사람
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
				else if (v1.get_act(i) == 2 && v1.get_intersection(i) == 1) {//올라가며 교차하는 사람
					v2.minus_pget_down(present2, 1);
					take_passengers1[people2[1]] = i;//탄순서 대로 
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					
				}
			}
		}
	}
	//내리는 부분
	people1[2] = people1[1];//people[2]가 최종적인 손님수가 되도록
	people2[2] = people2[1];

	for (int i = 0; i < 15; i++)
	{//엘베1
		if (present1 == v1.get_target(take_passengers1[i]) && v1.get_take(take_passengers1[i]) == 1)// 만약 타고있는사람의 목적지와 현재층이 같을때
		{
			if (v1.get_intersection(take_passengers1[i]) == 1 && present1 == 8) {//갈아타는 사람들
				v2.plus_pget_up(8);//층에 사람생성
				v2.plus_tget_up(v1.get_intersection_target(take_passengers1[i]));//층에 올라갈 사람 설정
				v1.take_down(take_passengers1[i]);
				v1.set_create(take_passengers1[i], 8);
				v1.set_act_1(take_passengers1[i]);
				v1.set_target(take_passengers1[i], v1.get_intersection_target(take_passengers1[i]));
				people1[2]--;//안에 사람줄음
				take_passengers1[i] = 1000;
			}
			else {//안갈아타는 사람들
				v1.take_down(take_passengers1[i]);//엘베내린거로 해줌
				people1[2]--;//안에 사람줄음
				take_passengers1[i] = 1000;
			}
		}

		//엘베2
		if (present2 == v1.get_target(take_passengers2[i]) && v1.get_take(take_passengers2[i]) == 1)
		{
			/*if (present2 != v1.get_intersection_target(take_passengers2[i]))
				;
			else {
				v1.take_down(take_passengers2[i]);
				people2[2]--;
				take_passengers2[i] = 1000;
			}*/
			if (v1.get_intersection(take_passengers2[i]) == 1 && present2 == 8) {//갈아타는 사람들
				v2.plus_pget_down(8);//층에 사람생성
				v2.plus_tget_down(v1.get_intersection_target(take_passengers2[i]));//층에 올라갈 사람 설정
				v1.take_down(take_passengers2[i]);
				v1.set_create(take_passengers2[i], 8);
				v1.set_act_2(take_passengers2[i]);
				v1.set_target(take_passengers2[i], v1.get_intersection_target(take_passengers2[i]));
				people2[2]--;//안에 사람줄음
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

void Elevators::go_create_oe(Floor &v1)//생성지로 ㄱㄱ
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
	for (int i = 0; i <= v1.get_person(); i++)//엘리베이터 타는부분
	{



		if (present1 == v1.get_create(i) && (present1 == 0 || present1 == 2 || present1 == 4 || present1 == 6 || present1 == 8 || present1 == 10 || present1 == 12 || present1 == 14 || present1 == 16))//타는것관련 엘베1옴
		{
			if (elevator_state1 == 1)//도착후 정지인경우 안에 손님없다는뜻!
			{
				if (v1.get_act(i) == 1)//올라갈 손님~
				{
					v2.minus_pget_up(present1, 1);
					take_passengers1[people1[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					destination1 = v1.get_target(i);
					elevator_state1 = 2;//먼저온 위로올라갈사람이 먼저탔으니 엘리베이터를 위로올라가는상태로바꿔줌
				}
				else if (v1.get_act(i) == 2)//내려갈 손님~
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
			else if (elevator_state1 == 2)//위
			{
				if (v1.get_act(i) == 1)//올라갈사람일때
				{
					if (people1[1] < 15)//15명보다 적을때 더 탈수있음
					{
						v2.minus_pget_up(present1, 1);
						take_passengers1[people1[1]] = i;//그사람이 누군지 저장
						v1.take_up(i);//그 사람 탄상태로
						v1.set_act(i);
						people1[1]++;//탄사람 증가
						if (v1.get_target(i) > destination1)
							destination1 = v1.get_target(i);//목적지가 더크면 바꿔줌
					}
				}
			}
			else if (elevator_state1 == 3)//아래
			{
				if (v1.get_act(i) == 2)//내려가는사람
				{
					if (people1[1] < 15)
					{
						v2.minus_pget_down(present1, 1);
						take_passengers1[people1[1]] = i;
						v1.take_up(i);
						v1.set_act(i);
						people1[1]++;
						if (v1.get_target(i) < destination1)
							destination1 = v1.get_target(i);//목적지가 더작으면 바꿔줌
					}
				}
			}
		}


		if (present2 == v1.get_create(i) && (present2 == 1 || present2 == 3 || present2 == 5 || present2 == 7 || present2 == 9 || present2 == 11 || present2 == 13 || present2 == 15))//타는것관련 엘베2옴
		{
			if (elevator_state2 == 1)//도착후 정지인경우 안에 손님없다는뜻!
			{
				if (v1.get_act(i) == 1)//올라갈 손님~
				{
					v2.minus_pget_up(present2, 1);
					take_passengers2[people2[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					destination2 = v1.get_target(i);
					elevator_state2 = 2;//먼저온 위로올라갈사람이 먼저탔으니 엘리베이터를 위로올라가는상태로바꿔줌
				}
				else if (v1.get_act(i) == 2)//내려갈 손님~
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
			else if (elevator_state2 == 2)//위
			{
				if (v1.get_act(i) == 1)//올라갈사람일때
				{
					if (people2[1] < 15)//15명보다 적을때 더 탈수있음
					{
						v2.minus_pget_up(present2, 1);
						take_passengers2[people2[1]] = i;//그사람이 누군지 저장
						v1.take_up(i);//그 사람 탄상태로
						v1.set_act(i);
						people2[1]++;//탄사람 증가
						if (v1.get_target(i) > destination2)
							destination2 = v1.get_target(i);//목적지가 더크면 바꿔줌
					}
				}
			}

			else if (elevator_state2 == 3)//아래
			{
				if (v1.get_act(i) == 2)//내려가는사람
				{
					if (people2[1] < 15)
					{
						v2.minus_pget_down(present2, 1);
						take_passengers2[people2[1]] = i;
						v1.set_act(i);
						v1.take_up(i);
						people2[1]++;
						if (v1.get_target(i) < destination1)
							destination1 = v1.get_target(i);//목적지가 더작으면 바꿔줌
					}
				}
			}
		}
	}
	//내리는 부분
	people1[2] = people1[1];//people[2]가 최종적인 손님수가 되도록
	people2[2] = people2[1];

	for (int i = 0; i < 15; i++)
	{//엘베1
		if (present1 == v1.get_target(take_passengers1[i]) && v1.get_take(take_passengers1[i]) == 1)// 만약 타고있는사람의 목적지와 현재층이 같을때
		{
			v1.take_down(take_passengers1[i]);//엘베내린거로 해줌
			people1[2]--;//안에 사람줄음
			take_passengers1[i] = 0;

		}

		//엘베2
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

void Elevators::go_go()//목적지는 지하2~15층 와리가리
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
	for (int i = 0; i <= v1.get_person(); i++)//엘리베이터 타는부분
	{



		if (present1 == v1.get_create(i))//타는것관련 엘베1옴
		{
			if (elevator_state1 == 1)//도착후 정지인경우 안에 손님없다는뜻!
			{
				if (v1.get_act(i) == 1)//올라갈 손님~
				{
					v2.minus_pget_up(present1, 1);
					take_passengers1[people1[1]] = i;//탄순서 대로 
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 2;//먼저온 위로올라갈사람이 먼저탔으니 엘리베이터를 위로올라가는상태로바꿔줌
				}
				else if (v1.get_act(i) == 2)//내려갈 손님~
				{
					v2.minus_pget_down(present1, 1);
					take_passengers1[people1[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people1[1]++;
					elevator_state1 = 3;
				}
			}
			else if (elevator_state1 == 2)//위
			{
				if (v1.get_act(i) == 1)//올라갈사람일때
				{
					if (people1[1] < 1)//15명보다 적을때 더 탈수있음
					{
						v2.minus_pget_up(present1, 1);
						take_passengers1[people1[1]] = i;//그사람이 누군지 저장
						v1.take_up(i);//그 사람 탄상태로
						v1.set_act(i);
						people1[1]++;//탄사람 증가
					}
				}
			}
			else if (elevator_state1 == 3)//아래
			{
				if (v1.get_act(i) == 2)//내려가는사람
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


		if (present2 == v1.get_create(i))//타는것관련 엘베2옴
		{
			if (elevator_state2 == 1)//도착후 정지인경우 안에 손님없다는뜻!
			{
				if (v1.get_act(i) == 1)//올라갈 손님~
				{
					v2.minus_pget_up(present2, 1);
					take_passengers2[people2[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					elevator_state2 = 2;//먼저온 위로올라갈사람이 먼저탔으니 엘리베이터를 위로올라가는상태로바꿔줌
				}
				else if (v1.get_act(i) == 2)//내려갈 손님~
				{
					v2.minus_pget_down(present2, 1);
					take_passengers2[people2[1]] = i;
					v1.take_up(i);
					v1.set_act(i);
					people2[1]++;
					elevator_state2 = 3;
				}
			}
			else if (elevator_state2 == 2)//위
			{
				if (v1.get_act(i) == 1)//올라갈사람일때
				{
					if (people2[1] < 15)//15명보다 적을때 더 탈수있음
					{
						v2.minus_pget_up(present2, 1);
						take_passengers2[people2[1]] = i;//그사람이 누군지 저장
						v1.take_up(i);//그 사람 탄상태로
						v1.set_act(i);
						people2[1]++;//탄사람 증가

					}
				}
			}

			else if (elevator_state2 == 3)//아래
			{
				if (v1.get_act(i) == 2)//내려가는사람
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
	//내리는 부분
	people1[2] = people1[1];//people[2]가 최종적인 손님수가 되도록
	people2[2] = people2[1];

	for (int i = 0; i < 15; i++)
	{//엘베1
		if (present1 == v1.get_target(take_passengers1[i]) && v1.get_take(take_passengers1[i]) == 1)// 만약 타고있는사람의 목적지와 현재층이 같을때
		{
			v1.take_down(take_passengers1[i]);//엘베내린거로 해줌
			people1[2]--;//안에 사람줄음
			take_passengers1[i] = 0;

		}

		//엘베2
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