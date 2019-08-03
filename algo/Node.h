#pragma once

namespace NodeTool{
	enum COLOR { RED, BLACK };
	
	template<typename T>
	class NodeOrig
	{
	private:
		NodeOrig * left;
		NodeOrig * right;
	protected:
		T data;
	public:
		NodeOrig() {}
		~NodeOrig() {}
		virtual void DeleteNode(NodeOrig* n) {}
		virtual void SetData(T data) {}
		virtual T GetData() = 0;
	};

	template<typename T>
	class hashNode : public NodeOrig<T>
	{
	public:

		enum DATAEXIST { NOTHING, EXISTING };
	protected:
		T data;
		DATAEXIST exist;
		hashNode* left;
		hashNode* right;
	public :
	
		hashNode() :NodeOrig<T>()
		{
			DATAEXIST = NOTHING;
		}
		hashNode(T data) :NodeOrig<T>()
		{
			this->SetData(data);
			this->SetDataExist(EXISTING);
			this->left = nullptr;
			this->right = nullptr;
		}
		void SetData(T data)
		{
			this->data = data;
		}
		void SetLeft(hashNode* left)
		{
			this->left = left;
		}
		void SetRight(hashNode* right) {
			this->right = right;

		}
		void SetDataExist(DATAEXIST exist)
		{
			this->exist = exist;
		}
		T GetData() {
			return data;

		}
		DATAEXIST GetDataExist()
		{
			return exist;
		}
		hashNode* GetLeft() {
			return left;
		}
		hashNode* GetRight() {
			return right;
		}
		void DeleteNode(hashNode* n) {
			if (n == nullptr) return;
			delete n;

		}
	
	};

	template<typename T>
	class generalNode :public NodeOrig<T>
	{
	private:
		T data;
		generalNode * left;
		generalNode * right;
	public:
		generalNode(T data) :NodeOrig<T>() {
			this->data = data;
			left = nullptr;
			right = nullptr;
		}

		~generalNode() {
			DeleteNode(left);
			DeleteNode(right);
		}

		void DeleteNode(generalNode* n) {
			if (n == nullptr) return;
			delete n;

		}
		void SetData(T data)
		{
			this->data = data;
		}
		void SetChild(generalNode* child)
		{
			this->left = child;
		}
		void SetSibling(generalNode* sibling) {
			this->right = sibling;

		}
		T GetData() {
			return data;

		}
		generalNode* GetChild() {
			return left;
		}
		generalNode* GetSibling() {
			return right;
		}
	};

	template<typename T>
	class Node :public NodeOrig<T>
	{
	private:
		T data;
		COLOR nodeColor;
	protected:
		Node * left;
		Node * right;
		Node * parent;
		Node * general_purpose;
	public:
		static Node<T>* makeNode(T data, COLOR col)
		{
			return new Node<T>(data, col);
		}

		Node() :NodeOrig<T>() {};

		Node(T data) :NodeOrig<T>() {
			this->data = data;
			this->left = nullptr;
			this->right = nullptr;
			this->parent = nullptr;
			this->nodeColor = RED;
		}

		Node(T data, COLOR col) :NodeOrig<T>() {
			this->data = data;
			this->left = nullptr;
			this->right = nullptr;
			this->parent = nullptr;
			this->general_purpose = nullptr;
			this->nodeColor = col;
		}
		Node(Node<T> *copy) :NodeOrig<T>() {
			this->data = copy->GetData();
			this->left = copy->GetLeft();
			this->right = copy->GetRight();
			this->parent = copy->GetParent();
			this->general_purpose = GetGP();
			this->nodeColor = copy->GetColor();
		}
		~Node() {
			//DeleteNode(left);
			//DeleteNode(right);
			//DeleteNode(parent);
		}

		void DeleteNode(Node* n) {
			if (n == nullptr) return;

			this->left = nullptr;
			this->right = nullptr;
			this->parent = nullptr;
			this->general_purpose = nullptr;
			delete n;

		}
		void SetData(T data)
		{
			this->data = data;
		}
		void SetLeft(Node* left)
		{
			this->left = left;
		}
		void SetRight(Node* right) {
			this->right = right;

		}
		void SetParent(Node* parent)
		{
			this->parent = parent;
		}
		int SetGP(Node<T>* general_purpose)
		{
			this->general_purpose = general_purpose;

			if (this->general_purpose == this->GetLeft())
			{
				return 1;
			}
			else if (this->general_purpose == this->GetRight())
			{
				return 1;
			}
			else if (this->general_purpose == this->GetParent())
			{
				return 1;
			}
			
			return 0;
		}
		T GetData() {
			return data;

		}
		Node* GetLeft() {
			return left;
		}
		Node* GetRight() {
			return right;
		}
		Node<T>* GetParent()
		{
			return this->parent;
		}
		Node<T>* GetGP()
		{
			return this->general_purpose;
		}
		Node<T>* GetGrandParent()
		{
			Node<T>* parent = this->GetParent();
			if (parent == nullptr) return nullptr;

			return parent->GetParent();
		}
		Node<T>* GetUncle()
		{
			Node<T>* grandParent = this->GetGrandParent();

			if (grandParent == nullptr) return nullptr;
			if (grandParent->GetLeft() == this->GetParent()) return grandParent->GetRight();
			return grandParent->GetLeft();
		}
		Node<T>* GetSibling()
		{
			if (parent == nullptr)return nullptr;
			if (isOnLeft()) return parent->right;
			return parent->left;
		}
		COLOR GetColor()
		{
			return this->nodeColor;
		}
		void SetColor(COLOR col)
		{
			this->nodeColor = col;
		}

		// check if node is left child of parent 
		bool isOnLeft() { return this == parent->left; }

		bool hasRedChild() {
			return (left != nullptr and left->GetColor() == RED) or
				(right != nullptr and right->GetColor() == RED);
		}

		// moves node down and moves given node in its place 
		void moveDown(Node *nParent) {
			if (parent != nullptr) {
				if (isOnLeft()) {
					parent->left = nParent;
				}
				else {
					parent->right = nParent;
				}
			}
			nParent->parent = parent;
			parent = nParent;
		}
	};
	/*

	template<typename T>
	class GraphNode : public Node<T>
	{
	private:

		T* data;
		Node * left;
		Node * right;
	public:
		GraphNode(T data)
		{
			data = ;
		}
	};*/
}