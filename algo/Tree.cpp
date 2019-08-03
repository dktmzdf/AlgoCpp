#include "Tree.h"



Tree::Tree()
{
	root = nullptr;
	pn = nullptr;

}


Tree::~Tree()
{
	delete root;
}

void Tree::setRoot(int data)
{
	root = new NodeTool::generalNode<int>(data);
}

void Tree::setPN(NodeTool::generalNode<int>* n)
{
	pn = n;
}

NodeTool::generalNode<int>* Tree::getRoot()
{
	return root;
}

NodeTool::generalNode<int>* Tree::getPN()
{
	return pn;
}

void Tree::NodeChangeData(int data)
{
	pn->SetData(data);
}

void Tree::parentInsertChild(int data)
{
	NodeTool::generalNode<int>* tmp;
	if (pn == nullptr) pn->SetChild(new NodeTool::generalNode<int>(data));
	else {
		tmp = pn->GetChild();
		if (tmp == nullptr) {
			pn->SetChild(new NodeTool::generalNode<int>(data));
			return;
		}
		while (true) {
			if (tmp->GetSibling() == nullptr) {
				tmp->SetSibling(new NodeTool::generalNode<int>(data));
				break;
			}
			tmp = tmp->GetSibling();
		}
	}
}

int Tree::parentDeleteChild(int data) //리턴값 0은 정상처리 1은 data를 찾지못함 -1 에러
{
	NodeTool::generalNode<int>* tmp = nullptr;
	NodeTool::generalNode<int>* pre = nullptr;
	tmp = pn->GetChild();
	if (tmp == nullptr) {
		return 1;
	}
	if (tmp->GetData() == data)
	{
		pn->SetChild(tmp->GetSibling());
		tmp->SetSibling(nullptr);
		delete tmp;
		return 0;
	}
	while (true)
	{
		pre = tmp;
		tmp = tmp->GetSibling();
		if (tmp == nullptr)return 1;
		if (tmp->GetData() == data) {
			pre->SetSibling(tmp->GetSibling());
			tmp->SetSibling(nullptr);
			delete tmp;
			break;
		}
	}
	if (tmp == nullptr) return 1;

	return -1;
}

int Tree::returnChild()
{
	NodeTool::generalNode<int>* tmp = pn->GetChild();
	if (tmp == nullptr) return 1;
	else {
		while (true){
			if (tmp == nullptr) break;
			return tmp->GetData();
		}
	}

	return -1;
}
