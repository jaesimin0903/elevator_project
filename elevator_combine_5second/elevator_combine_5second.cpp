#include <conio.h>//_kbhit(),_getch() 를쓰기위한 헤더
#include <Windows.h>
#include <iostream>
#include <stdlib.h>//랜덤쓰기위해서
#include <time.h>//랜덤바꾸기위해서
#include <algorithm>
#include<vector>
using namespace std;
#include "floor.h"
#include "passengers.h"
#include "elevators.h"


int rest(Passengers &v1, Elevators &v2);
void Elevator_GUI(Passengers &v1, Elevators &v2, Floor &v3);
void normal_elevator();
void normal_elevator_plus();
void normal_elevator_plus_plus();
void even_odd_elevator();
void up_down_elevator();
void FIFO_elevator();


int main()
{
	srand((int)time(NULL));//시드값 바꿔주기
	int a;
	while (1)
	{
		cout << "\n\t엘리베이터 종합 프로그래밍\n\n" << endl;

		cout << "1.normal_elevator(평범한 엘리베이터)" << endl;
		cout << "2.normal_elevator+(첫번째 엘리베이터 우선권)" << endl;
		cout << "3.normal_elevator++(B2~6F,7F~15F 스위치만 받는 엘리베이터1,2)" << endl;
		cout << "4.even_odd_elevator(짝수층,홀수층만 내리고타는 엘리베이터)" << endl;
		cout << "5.up_down_elevator(B2~15왔다갔다 단순한 엘리베이터)" << endl;
		cout << "6.exit" << endl;
		cout << "7.FIFO" << endl;

		cout << "\n번호를 입력해주세요>> " << endl;
		cin >> a;
		system("cls");
		if (a > 6 || a < 1)
			cout << "해당 번호는 없습니다 다시 입력해주세요" << endl;

		if (a == 6)
			break;
		switch (a)
		{
		case 1:
			normal_elevator();
			break;
		case 2:
			normal_elevator_plus();
			break;
		case 3:
			normal_elevator_plus_plus();
			break;
		case 4:
			even_odd_elevator();
			break;
		case 5:
			up_down_elevator();
			break;
		case 7:
			FIFO_elevator();
			break;
		}
	}

	return 0;
}

int rest(Passengers &v1, Elevators &v2)
{
	int rest = 0;
	for (int i = 0; i <= v1.get_person(); i++)
	{
		if (v1.get_act(i) == 1 || v1.get_act(i) == 2)
			rest++;
	}
	rest = rest + v2.get_people1() + v2.get_people2();
	return rest;
}

void Elevator_GUI(Passengers &v1, Elevators &v2, Floor &v3)
{


	for (int i = 16; i >= 2; i--)
	{

		cout << "|        " << i - 1;
		if (i - 1 < 10)
			cout << " ";
		cout << "F           ";

		if (v2.get_present1() == i)
		{
			cout << "■ " << v2.get_present1() - 1;
			if (v2.get_present1() - 1 < 10)
				cout << " ";
			cout << " ■";
		}
		else
			cout << "        ";
		if (v2.get_present2() == i)
		{
			cout << "    ■ ";
			cout << v2.get_present2() - 1;
			if (v2.get_present2() - 1 < 10)
				cout << " ";
			cout << " ■";
		}
		else
			cout << "           ";

		if (i == 8)
			cout << "\t(a) 멈춤 (b) 추가승객 (c)생성지목적지설정하는승객생성" << endl;
		else
			cout << endl;
		//
		cout << "|            [" << v3.pget_up(i);
		if (v3.pget_up(i) < 10)
			cout << " ";
		cout << "]▲    ";

		if (v2.get_present1() == i)
		{
			if (v2.get_door1() == 1)
				cout << "  ";
			else
				cout << "■";
			cout << "[" << v2.get_people1();
			if (v2.get_people1() < 10)
				cout << " ";
			cout << "]■    ";
		}
		else
			cout << "            ";
		if (v2.get_present2() == i)
		{
			if (v2.get_door2() == 1)
				cout << "  ";
			else
				cout << "■";
			cout << "[" << v2.get_people2();
			if (v2.get_people2() < 10)
				cout << " ";
			cout << "]■";//엘리베이터 둘째줄
		}
		else
			cout << "        ";
		if (i == 10)
		{
			cout << "\t\t엘리베이터1 목적지: ";
			if (v2.get_destination1() > 1)
				cout << v2.get_destination1() - 1 << "F";
			else
				cout << "B" << 2 - v2.get_destination1();
		}
		if (i == 8)
			cout << "\t(d)승객 생성된 시간 (e)종료";
		if (i == 12)
			cout << "\t\t생성된사람수: " << v1.get_person() << endl;
		else
			cout << endl;

		
		//
		cout << "|            [" << v3.pget_down(i);
		if (v3.pget_down(i) < 10)
			cout << " ";
		cout << "]▼    ";

		if (v2.get_present1() == i)
			cout << "■■■■";
		else
			cout << "        ";
		if (v2.get_present2() == i)
			cout << "    ■■■■";//엘리베이터 셋째줄
		else
			cout << "            ";
		
		if (i == 10)
		{
			cout << "\t\t엘리베이터2 목적지: ";
			if (v2.get_destination2() > 1)
				cout << v2.get_destination2() - 1 << "F";
			else
				cout << "B" << 2 - v2.get_destination2();
		}
		if (i == 12)
			cout << "\t\t남은사람수: " << rest(v1, v2) << "\t\ttimestamp : " << v2.time_Stamp() <<"\t최대승객대기시간 : " <<v1.sleep_time() <<  endl;
		else
			cout << endl;
	}
	//////지하
	for (int i = 1; i >= 0; i--)
	{

		cout << "|        B" << 2 - i;
		if (2 - i < 10)
			cout << " ";
		cout << "           ";

		if (v2.get_present1() == i)
		{
			cout << "■ B" << 2 - v2.get_present1();
			if (2 - v2.get_present1() < 10)
				cout << " ";
			cout << "■";
		}
		else
			cout << "        ";
		if (v2.get_present2() == i)
		{
			cout << "    ■ B";
			cout << 2 - v2.get_present2();
			if (2 - v2.get_present2() < 10)
				cout << " ";
			cout << "■" << endl;
		}
		else
			cout << "           " << endl;

		//
		cout << "|            [" << v3.pget_up(i);
		if (v3.pget_up(i) < 10)
			cout << " ";
		cout << "]▲    ";

		if (v2.get_present1() == i)
		{
			if (v2.get_door1() == 1)
				cout << "  ";
			else
				cout << "■";
			cout << "[" << v2.get_people1();
			if (v2.get_people1() < 10)
				cout << " ";
			cout << "]■    ";
		}
		else
			cout << "            ";
		if (v2.get_present2() == i)
		{
			if (v2.get_door2() == 1)
				cout << "  ";
			else
				cout << "■";
			cout << "[" << v2.get_people2();
			if (v2.get_people2() < 10)
				cout << " ";
			cout << "]■" << endl;//엘리베이터 둘째줄
		}
		else
			cout << "        " << endl;
		//
		cout << "|            [" << v3.pget_down(i);
		if (v3.pget_down(i) < 10)
			cout << " ";
		cout << "]▼    ";

		if (v2.get_present1() == i)
			cout << "■■■■";
		else
			cout << "        ";
		if (v2.get_present2() == i)
			cout << "    ■■■■" << endl;//엘리베이터 셋째줄
		else
			cout << "            " << endl;
	}
	cout << "\t엘리베이터 1 승객 현황 : ";

	for (int j = 0;j < 15;j++) {
		cout <<" | " << v1.get_target(v2.get_take_passengers1(j));
	}
	cout << endl;
	cout << "\t엘리베이터 2 승객 현황 : ";

	for (int j = 0;j < 15;j++) {
		cout << " | " << v1.get_target(v2.get_take_passengers2(j));
	}
	cout << endl;
	cout << v2.get_people1() <<" "<< v2.get_people1_2() << " " << v2.get_people1_3();
}

void normal_elevator_plus()
{
	Elevators e;
	Passengers p;
	Floor f;
	int a = 1;

	Elevator_GUI(p, e, f);
	Sleep(100);
	while (a)
	{
		system("cls");
		try
		{
			if (p.get_person() >= 999)
				throw p.get_person();
			////
			p.Produce_passenger(f);
			e.go_target_np(p);
			e.go_create_np(f);
			e.Elevator_state();
			e.take_in_out(p, f);
			e.Elevator_move_take_in_out(p, f);
			Elevator_GUI(p, e, f);
			Sleep(100);
			p.time_flow();
			e.set_door1();
			e.set_door2();
		}
		catch (int e)
		{
			cout << "경고!더 실행시킬시 승객생성 1000명이상입니다" << endl;
			cout << "현재 생성된 승객수: " << e << endl;
			cout << "승객정보를 저장할수 있는공간이 더이상없습니다 프로그램을 종료합니다" << endl;
			break;
		}
		////

		if (_kbhit())//키보드 눌렀니 체크 1반환
		{
			
			switch (_getch())//키보드로 입력받은것 문자임!
			{
			case 'a':
				cout << "재개 아무키나 눌러주세요" << endl;
				system("pause");
				break;
			case 'b':
				int x;
				cout << "추가할 승객수 입력" << endl;
				cin >> x;
				for (int i = 0; i < x; i++)
					p.Produce_passenger(f);
				break;
			case 'c':
				p.produce_choose(f);
				break;
			case 'd':
				system("cls");
				p.sleep_time();
				system("pause");
				break;
			case 'e':
				cout << "종료합니다!" << endl;
				a = 0;
			}

		}
	}
}

void normal_elevator()
{
	Elevators e;
	Passengers p;
	Floor f;
	int a = 1;

	Elevator_GUI(p, e, f);
	Sleep(10);
	while (a)
	{
		system("cls");
		try
		{
			//if (p.get_person() >= 999)
			//	throw p.get_person();
			////
			p.Produce_passenger(f);
			e.go_target_n(p);
			e.go_create_n(f);
			e.Elevator_state();
			e.take_in_out(p, f);
			e.Elevator_move_take_in_out(p, f);
			Elevator_GUI(p, e, f);
			Sleep(10);
			p.time_flow();
			e.set_door1();
			e.set_door2();
		}
		catch (int e)
		{
			cout << "경고!더 실행시킬시 승객생성 1000명이상입니다" << endl;
			cout << "현재 생성된 승객수: " << e << endl;
			cout << "승객정보를 저장할수 있는공간이 더이상없습니다 프로그램을 종료합니다" << endl;
			break;
		}
		////

		if (_kbhit())//키보드 눌렀니 체크 1반환
		{
			
			switch (_getch())//키보드로 입력받은것 문자임!
			{
			case 'a':
				cout << "재개 아무키나 눌러주세요" << endl;
				system("pause");
				break;
			case 'b':
				int x;
				cout << "추가할 승객수 입력" << endl;
				cin >> x;
				for (int i = 0; i < x; i++)
					p.Produce_passenger(f);
				break;
			case 'c':
				p.produce_choose(f);
				break;
			case 'd':
				system("cls");
				p.sleep_time();
				system("pause");
				break;
			case 'e':
				cout << "종료합니다!" << endl;
				a = 0;
			}

		}
	}
}


void normal_elevator_plus_plus()
{
	Elevators e(0,0,8,8);
	Passengers p;
	Floor f;
	int a = 1;

	Elevator_GUI(p, e, f);
	Sleep(10);
	while (a)
	{
		system("cls");

		////
		p.Produce_passenger(f);
		e.go_target_npp(p);
		e.go_create_npp(f);
		e.Elevator_state();
		e.take_in_out_npp(p, f);
		e.Elevator_move_take_in_out(p, f);
		Elevator_GUI(p, e, f);
		Sleep(10);
		p.time_flow();
		e.set_door1();
		e.set_door2();
		if (rest(p,e) == 0) break;
		////

		if (_kbhit())//키보드 눌렀니 체크 1반환
		{
			
			switch (_getch())//키보드로 입력받은것 문자임!
			{
			case 'a':
				cout << "재개 아무키나 눌러주세요" << endl;
				system("pause");
				break;
			case 'b':
				int x;
				cout << "추가할 승객수 입력" << endl;
				cin >> x;
				for (int i = 0; i < x; i++)
					p.Produce_passenger(f);
				break;
			case 'c':
				p.produce_choose(f);
				break;
			case 'd':
				system("cls");
				p.sleep_time();
				system("pause");
				break;
			case 'e':
				cout << "종료합니다!!" << endl;
				a = 0;
			}

		}
	}
}

void even_odd_elevator()
{
	Elevators e(0, 0, 1, 1);
	Passengers p;
	Floor f;
	int a = 1;

	Elevator_GUI(p, e, f);
	Sleep(1);
	while (a)
	{
		system("cls");

		try
		{
			if (p.get_person() >= 999 && rest(p,e) == 0)
				throw p.get_person();
			////
			p.Produce_passenger_oe(f);
			e.go_create_oe(f);
			e.Elevator_state();
			e.take_in_out_oe(p, f);
			e.Elevator_move_take_in_out(p, f);
			Elevator_GUI(p, e, f);
			Sleep(1);
			p.time_flow();
			e.set_door1();
			e.set_door2();
		}
		catch (int e)
		{
			cout << "경고!더 실행시킬시 승객생성 1000명이상입니다" << endl;
			cout << "현재 생성된 승객수: " << e << endl;
			cout << "승객정보를 저장할수 있는공간이 더이상없습니다 프로그램을 종료합니다" << endl;
			break;
		}
		////

		if (_kbhit())//키보드 눌렀니 체크 1반환
		{
			
			switch (_getch())//키보드로 입력받은것 문자임!
			{
			case 'a':
				cout << "재개 아무키나 눌러주세요" << endl;
				system("pause");
				break;
			case 'b':
				int x;
				cout << "추가할 승객수 입력" << endl;
				cin >> x;
				for (int i = 0; i < x; i++)
					p.Produce_passenger(f);
				break;
			case 'c':
				p.produce_choose_oe(f);
				break;
			case 'd':
				system("cls");
				p.sleep_time();
				system("pause");
				break;
			case 'e':
				cout << "종료합니다!" << endl;
				a = 0;
			}

		}
	}
}

void up_down_elevator()
{
	Elevators e;
	Passengers p;
	Floor f;
	int a = 1;

	Elevator_GUI(p, e, f);
	Sleep(40);
	while (a)
	{
		system("cls");

		try
		{
			if (p.get_person() >= 999 && rest(p,e) == 0)
				throw p.get_person();
			////
			p.Produce_passenger(f);
			e.go_go();
			e.Elevator_state();
			e.take_in_out(p, f);
			e.Elevator_move_take_in_out(p, f);
			Elevator_GUI(p, e, f);
			Sleep(40);
			p.time_flow();
			e.set_door1();
			e.set_door2();
			
		}
		catch (int e)
		{
			cout << "경고!더 실행시킬시 승객생성 1000명이상입니다" << endl;
			cout << "현재 생성된 승객수: " << e << endl;
			//cout << "timestamp : " << e.time_Stamp() << endl;
			cout << "승객정보를 저장할수 있는공간이 더이상없습니다 프로그램을 종료합니다" << endl;
			break;
		}
		////

		if (_kbhit())//키보드 눌렀니 체크 1반환
		{
			
			switch (_getch())//키보드로 입력받은것 문자임!
			{
			case 'a':
				cout << "재개 아무키나 눌러주세요" << endl;
				system("pause");
				break;
			case 'b':
				int x;
				cout << "추가할 승객수 입력" << endl;
				cin >> x;
				for (int i = 0; i < x; i++)
					p.Produce_passenger(f);
				break;
			case 'c':
				p.produce_choose(f);
				break;
			case 'd':
				system("cls");
				p.sleep_time();
				system("pause");
				break;
			case 'e':
				cout << "종료합니다!" << endl;
				a = 0;
			}

		}
	}
}

void FIFO_elevator()
{
	Elevators e;
	Passengers p;
	Floor f;
	int a = 1;

	Elevator_GUI(p, e, f);
	Sleep(100);
	while (a)
	{
		system("cls");
		try
		{
			if (p.get_person() >= 999)
				throw p.get_person();
			////
			p.Produce_passenger(f);
			e.go_target_n(p);
			e.go_create_n(f);
			e.Elevator_state();
			e.take_in_outFIFO(p, f);
			e.Elevator_move_take_in_out(p, f);
			Elevator_GUI(p, e, f);
			Sleep(100);
			p.time_flow();
			e.set_door1();
			e.set_door2();
		}
		catch (int e)
		{
			cout << "경고!더 실행시킬시 승객생성 1000명이상입니다" << endl;
			cout << "현재 생성된 승객수: " << e << endl;
			cout << "승객정보를 저장할수 있는공간이 더이상없습니다 프로그램을 종료합니다" << endl;
			break;
		}
		////

		if (_kbhit())//키보드 눌렀니 체크 1반환
		{

			switch (_getch())//키보드로 입력받은것 문자임!
			{
			case 'a':
				cout << "재개 아무키나 눌러주세요" << endl;
				system("pause");
				break;
			case 'b':
				int x;
				cout << "추가할 승객수 입력" << endl;
				cin >> x;
				for (int i = 0; i < x; i++)
					p.Produce_passenger(f);
				break;
			case 'c':
				p.produce_choose(f);
				break;
			case 'd':
				system("cls");
				p.sleep_time();
				system("pause");
				break;
			case 'e':
				cout << "종료합니다!" << endl;
				a = 0;
			}

		}
	}
}