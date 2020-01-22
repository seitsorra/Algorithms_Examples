#include "../../utils.h"

template <class T>
class MyLinkList
{
    struct Node
    {
        T data;
        Node *next;
        Node(const T &data_, Node *next_)
        {
            this->data = data_;
            this->next = next_;
        }
    };

    Node *head = nullptr, *tail = nullptr;

    // Methods
    void removeKthLastHelper(Node *prev, Node *curr, int kThElem, int &counter){
        if (curr == nullptr){
            return;
        }
        removeKthLastHelper(curr, curr->next, kThElem, counter);
        counter++;
        if(counter == kThElem){
            if(prev == nullptr){
                head = head->next;
            }
            else{
                prev->next = curr->next;
            }
            delete curr;
        }
    }
    void removeNode(Node* n){
        if(n == nullptr || n->next == nullptr){
            return;
        }
        cout << "Removing node : " << n->data << endl;
        Node* tmp = n->next;
        n->data = n->next->data;
        n->next = n->next->next;
        delete tmp;
    }

public:
    //nesting iterators to avoid naming conflicts, these are public
    //as we want non-members to be able to create and use them.
    class const_iterator
    {
        friend class MyLinkList;
        Node *curr_;
        const MyLinkList *myList_;

    protected:
        const_iterator(Node *curr, const MyLinkList *list)
        {
            curr_ = curr;
            myList_ = list;
        }

    public:
        const_iterator operator++()
        {
            curr_ = curr_->next;
            return *this;
        }
        const T &operator*() const
        {
            T rc = T{};
            if (curr_)
            {
                return curr_->data;
            }
            return rc;
        }
        bool operator==(const_iterator right) const
        {
            return (curr_ == right.curr_);
        }
        bool operator!=(const_iterator right) const
        {
            return (curr_ != right.curr_);
        }
    };
    class iterator : public const_iterator
    {
        friend class MyLinkList;
        iterator(Node *curr, const MyLinkList *list) : const_iterator(curr, list)
        {
        }

    public:
        T &operator*()
        {
            if (const_iterator::curr_)
            {
                return const_iterator::curr_->data;
            }
        }
        const T &operator*() const
        {
            if (const_iterator::curr_)
            {
                return const_iterator::curr->data;
            }
        }
    };

    iterator begin()
    {
        return iterator(head, this);
    }
    const_iterator begin() const
    {
        return const_iterator(head, this);
    }
    iterator end()
    {
        return iterator(nullptr, this);
    }
    const_iterator end() const
    {
        return const_iterator(nullptr, this);
    }

    MyLinkList::MyLinkList()
    {
        head = tail = nullptr;
    }

    void MyLinkList::push_front(const T &data)
    {
        Node *tmp = new Node(data, head);
        head = tmp;
        if (tail == nullptr)
        {
            tail = tmp;
        }
    }

    void MyLinkList::push_back(const T &data)
    {
        Node *tmp = new Node(data, nullptr);
        if (tail == nullptr)
        {
            head = tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }
    }

    void MyLinkList::popFront()
    {
        if (head != nullptr)
        {
            Node *curHead = head;
            head = head->next;
            if (head == nullptr)
            {
                tail = nullptr;
            }
            delete curHead;
        }
    }

    void MyLinkList::popBack()
    {
        if (head != nullptr)
        {
            // For when there is a single item in the list
            if (head != tail)
            {
                Node *seondLast = head;
                while (seondLast->next != tail)
                {
                    seondLast = seondLast->next;
                }
                delete tail;
                tail = seondLast;
                tail->next = nullptr;
            }
            else
            {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
        }
    }

    void printList()
    {
        Node *tmp = head;
        while (tmp != nullptr)
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    // this will run O(n) time | O(n) space
    ///TODO: this function does assure that tail will be point to right node after the completion
    void removeUnique_usingDataBuffer()
    {
        unordered_map<int, bool> duplicates;
        Node *tmp = head;
        Node *prevTmp = nullptr;
        while (tmp != nullptr)
        {
            if (duplicates.find(tmp->data) != duplicates.end())
            {
                prevTmp->next = tmp->next;
                delete tmp;
                tmp = prevTmp;
            }
            else
            {
                duplicates.insert({tmp->data, true});
                prevTmp = tmp;
            }
            tmp = tmp->next;
        }
    }

    // this will run O(n^2) time | O(1) space
    ///TODO: this function does assure that tail will be point to right node after the completion
    void removeUnique()
    {
        if (head == nullptr)
        {
            return;
        }
        Node *cur = head;
        while (cur != nullptr)
        {
            Node *runnerNode = cur;
            while (runnerNode->next != nullptr)
            {
                if (runnerNode->next->data == cur->data)
                {
                    Node *duplicate = runnerNode->next;
                    runnerNode->next = runnerNode->next->next;
                    delete duplicate;
                }
                else
                {
                    runnerNode = runnerNode->next;
                }
            }
            cur = cur->next;
        }
    }

    void removeKthLast(int kElem)
    {
        int totalSize = 0;
        Node *cur = head;
        while (cur != nullptr)
        {
            totalSize++;
            cur = cur->next;
        }

        Node *prev = nullptr;
        cur = head;
        while (cur != nullptr)
        {
            if (totalSize == kElem)
            {
                if (prev == nullptr)
                {
                    head = head->next;
                }
                else
                {
                    prev->next = cur->next;
                }
                delete cur;
                cur = nullptr;
            }
            else
            {
                prev = cur;
                cur = cur->next;
                totalSize--;
            }
        }
    }

    void removeKthLastRecursive(int kElem){
        int counter = 0;
        removeKthLastHelper(nullptr, head, kElem, counter);
    }

    
    void removeInMiddle(){
        Node* tmp = head;
        for(int i = 1; i <= 2; i++) tmp = tmp->next;
        removeNode(tmp);
    }

    /*
    This method will partion the list around val
    such that all nodes with value less than val will be before nodes with value val
    */
    void partitionAroundNum(int val){
        Node* cur = head;
        Node* nodeAtVal = nullptr;

        Node* afterEnd = nullptr;
        Node* afterStart = nullptr;
        Node* beforeEnd = nullptr;
        Node* beforeStart = nullptr;

        while(cur != nullptr){
            Node* nextNode = cur->next;

            if(cur->data < val){
                if(beforeStart == nullptr){
                    beforeStart = cur;
                }
                else{
                    if(beforeEnd == nullptr){
                        beforeEnd = cur;
                        beforeStart->next = beforeEnd;
                    }
                    else{
                        beforeEnd->next = cur;
                    }
                }
            }
            else{
                if(afterStart == nullptr){
                    afterStart = cur;
                }
                else{
                    if(afterEnd == nullptr){
                        afterEnd = cur;
                        afterStart->next = afterEnd;
                    }
                    else{
                        afterEnd->next = cur;
                    }
                    ///TODO:
                    /*
                    In the following I am trying to get the node that matches the provided value be exactly where
                    two half join, but it does not seem to work for some reason ??? 

                    if(cur->data <= afterStart->data){
                        Node* tmp = afterStart;
                        afterStart = cur;
                        afterStart->next = tmp;
                        if(afterEnd == nullptr){
                            afterEnd = tmp;
                        }
                    }
                    else{
                        if(afterEnd == nullptr){
                            afterEnd = cur;
                            afterStart->next = afterEnd;
                        }
                        else{
                            afterEnd->next = cur;
                        }
                    }*/
                }
            }
            cur = nextNode;
        }
        head = beforeStart;
        beforeEnd->next = afterStart;
        afterEnd->next = nullptr;
    }
};