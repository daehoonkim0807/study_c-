#include <iostream>
using namespace std;

class Marine
{
	int hp; // 마린 체력
	int coord_x, coord_y; // 마린 위치
	int damage; // 공격력 
	bool is_dead;

public:
	Marine(); // 기본 생성자
	Marine(int x, int y); // x, y 좌표에 마린 생성

	int attack(); // 데미지를 리턴한다.
	void be_attacked(int damage_earn); // 입는 데미지
	void move(int x, int y); // 새로운 위치

	void show_status(); // 상태를 보여준다.
};
Marine::Marine() : hp(50), coord_x(0), coord_y(0),
	damage(5), is_dead(false) {}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50),
	damage(5), is_dead(false) {}

void Marine::move(int x, int y)
{
	coord_x = x;
	coord_y = y;
}
int Marine::attack()
{
	return damage;
}
void Marine::be_attacked(int damage_earn)
{
	hp -= damage_earn;
	if(hp <= 0)
		is_dead = true;
}
void Marine::show_status()
{
	cout << " *** Marine *** " << endl;
	cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
	cout << " HP : " << hp << endl;
}

int main()
{
	Marine* marines [100];
	marines[0] = new Marine(2,3); // new에 경우 객체를 동적으로 생성하면서와 동시에 자동으로 생성자도 호출해준다는 점입니다.
	marines[1] = new Marine(3,5);
	
	marines[0] -> show_status();
	marines[1] -> show_status();
	
	cout << endl << "마린 1이 마린 2를 공격 ! " << endl;
	
	marines[0] -> be_attacked(marines[1] -> attack());
	
	marines[0] -> show_status(); // Marine 들의 포인터를 가리키는 배열이기 때문에 메서드를 호출할 때. 이 아니라 ->를 사용해줘야겠다. 
	
	marines[1] -> show_status();
	
	delete marines[0]; // 마지막으로 동적으로 할당한 메모리는 언제나 해제해 주어야 된다는 원칙에 따라 해줘야 한다.	
	delete marines[1];
}

