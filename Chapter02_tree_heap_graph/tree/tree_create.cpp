#include <iostream>
#include <queue>

struct node {
	std::string postion;
	node* first;
	node* second;
};

/*
* 회사 조직도를 만들어보자!
*/

struct org_tree {
	node* root;

	/*
	* 루트 노드를 생성하는 함수
	*/
	static org_tree create_org_structure(const std::string& pos) {
		org_tree tree;
		tree.root = new node{ pos, NULL, NULL };
		return tree;
	}

	/*
	* 특정 직책 이름에 해당하는 노드를 찾아서 반환하는 함수.
	*/
	static node* find(node* root, const std::string& value) {
		if (root == NULL) {
			return NULL;
		}

		if (root->postion == value) {
			return root;
		}

		auto firstFound = org_tree::find(root->first, value);

		if (firstFound != NULL) {
			return firstFound;
		}

		return org_tree::find(root->second, value);
	}

	/*
	* 부하 직원을 추가하는 함수.
	* 상사의 직책 이름과 부하 직원의 직책 이름을 인자로 받는다.
	* 이 때 상사의 직책은 이미 트리에 존재한다.
	*/
	bool addSubordinate(const std::string& manager, const std::string& subordinate) {
		auto managerNode = org_tree::find(root, manager);

		if (!managerNode) {
			std::cout << manager << "을(를) 찾을 수 없습니다: " << std::endl;
			return false;
		}
		
		if (managerNode->first && managerNode->second) {
			std::cout << manager << " 아래에 " << subordinate << "을(를) 추가할 수 없습니다." << std::endl;
			return false;
		}

		if (!managerNode->first) {
			managerNode->first = new node{ subordinate, NULL, NULL };
		}
		else {
			managerNode->second = new node{ subordinate, NULL, NULL };
		}

		std::cout << manager << " 아래에 " << subordinate << "을(를) 추가했습니다." << std::endl;

		return true;
	}
};

int main(int argc, char* argv[]) {
	auto tree = org_tree::create_org_structure("CEO");

	tree.addSubordinate("CEO", "부사장");
	tree.addSubordinate("부사장", "IT부장");
	tree.addSubordinate("부사장", "마케팅부장");
	tree.addSubordinate("IT부장", "보안팀장");
	tree.addSubordinate("IT부장", "앱개발팀장");
	tree.addSubordinate("마케팅부장", "물류팀장");
	tree.addSubordinate("마케팅부장", "홍보팀장");
	tree.addSubordinate("부사장", "재무부장");
}