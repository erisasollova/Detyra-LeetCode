#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    //Time O(n)
    //Space O(1)
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    //Time O(n)
     //Space O(1)
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;

        ListNode* slow = head, * fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) return true;
        }

        return false;
    }

    //Time O(n)
    //Space O(1)
    int getDecimalValue(ListNode* head) {
        int num = 0;
        while (head) {
            num = num * 2 + head->val;
            head = head->next;
        }
        return num;
    }

    //Time O(n)
    //Space O(1)
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    //Time O(n)
    //Space O(1)
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode list(0);
        ListNode* tail = &list;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            }
            else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        tail->next = list1 ? list1 : list2;

        return list.next;
    }

    //Time O(n)
    //Space O(1)
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    //Time O(n)
    //Space O(1)
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);

        return root;
    }

    void printTree(TreeNode* root) {
        if (root == nullptr)
            return;

        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }

    //Time O(n)
    //Space O(1)
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        if (leftDepth > rightDepth)
            return leftDepth + 1;
        else
            return rightDepth + 1;
    }

    //Time O(n)
    //Space O(1)
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr)
            return minDepth(root->right) + 1;
        if (root->right == nullptr)
            return minDepth(root->left) + 1;

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }

    //Time O(n)
    //Space O(1)
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val)
            return root;

        if (val < root->val)
            return searchBST(root->left, val);

        return searchBST(root->right, val);
    }

    //Time O(n)
    //Space O(1)
    int maxDepth(string s) {
        stack<char> parentheses;
        int max_depth = 0;
        int current_depth = 0;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (c == '(') {
                parentheses.push(c);
                current_depth++;
            }
            else if (c == ')') {
                parentheses.pop();
                current_depth--;
            }
            max_depth = max(max_depth, current_depth);
        }

        return max_depth;
    }

    //Time O(n)
    //Space O(n)
    string makeGood(string s) {
        stack<char> st;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (!st.empty() && (st.top() == c + 32 || st.top() == c - 32)) {
                st.pop();
            }
            else {
                st.push(c);
            }
        }

        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }

    //Time O(n)
    //Space O(n)
    string removeOuterParentheses(string s) {
        string result;
        int level = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                if (level > 0) result += s[i];
                level++;
            }
            else {
                level--;
                if (level > 0) result += s[i];
            }
        }

        return result;
    }

    //Time O(n)
    //Space O(n)
    bool isValid(string s) {

        stack<char> brackets;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (c == '(' || c == '{' || c == '[') {
                brackets.push(c);
            }
            else {
                if (brackets.empty()) {
                    return false;
                }

                char top = brackets.top();
                brackets.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        return brackets.empty();
    }
};

class RecentCounter {
private:
    queue<int> q;
public:

    //Time O(1)
    //Space O(n)
    RecentCounter() {}

    int ping(int t) {
        q.push(t);

        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        return q.size();
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    RecentCounter recentCounter;
    int choice;

    cout << "Choose which function to test: " << endl;
    cout << "1. reverseList" << endl;
    cout << "2. hasCycle" << endl;
    cout << "3. getDecimalValue" << endl;
    cout << "4. middleNode" << endl;
    cout << "5. mergeTwoLists" << endl;
    cout << "6. isSameTree" << endl;
    cout << "7. invertTree" << endl;
    cout << "8. maxDepth (TreeNode)" << endl;
    cout << "9. minDepth" << endl;
    cout << "10. searchBST" << endl;
    cout << "11. maxDepth (TreeNode) " << endl;
    cout << "12. makeGood" << endl;
    cout << "13. removeOuterParentheses" << endl;
    cout << "14. isValid" << endl;
    cout << "15. recentCounter" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {

        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);

        ListNode* reversedHead = sol.reverseList(head);
        cout << "Reversed list: ";
        printList(reversedHead);

        ListNode* head1 = new ListNode(1);
        head1->next = new ListNode(2);

        ListNode* reversedHead1 = sol.reverseList(head1);
        cout << "Reversed list: ";
        printList(reversedHead1);

        //-------------------------------------------------------------------

        ListNode* head2 = new ListNode();

        ListNode* reversedHead2 = sol.reverseList(head2);
        cout << "Reversed list: ";
        printList(reversedHead2);

        break;

    }
    case 2: {

        ListNode* head = new ListNode(3);
        head->next = new ListNode(2);
        head->next->next = new ListNode(0);
        head->next->next->next = new ListNode(-4);
        head->next->next->next->next = head->next;

        cout << "Has cycle 1 : " << sol.hasCycle(head) << endl;

        //---------------------------------------------------------------------

        ListNode* head2 = new ListNode(1);
        head2->next = new ListNode(2);

        cout << "Has cycle 2 : " << sol.hasCycle(head2) << endl;

        //--------------------------------------------------------------------

        ListNode* head3 = new ListNode(1);

        cout << "Has cycle 3 : " << sol.hasCycle(head3) << endl;

        break;
    }
    case 3: {

        ListNode* head = new ListNode(1);
        head->next = new ListNode(0);
        head->next->next = new ListNode(1);

        cout << "Decimal value: " << sol.getDecimalValue(head) << endl;

        //--------------------------------------------------------------------

        ListNode* head2 = new ListNode();

        cout << "Decimal value: " << sol.getDecimalValue(head2) << endl;

        break;
    }
    case 4: {

        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);

        ListNode* middle = sol.middleNode(head);
        cout << "Middle node value: " << middle->val << endl;

        //--------------------------------------------------------------------


        ListNode* head2 = new ListNode(1);
        head2->next = new ListNode(2);
        head2->next->next = new ListNode(3);
        head2->next->next->next = new ListNode(4);
        head2->next->next->next->next = new ListNode(5);
        head2->next->next->next->next->next = new ListNode(6);


        ListNode* middle2 = sol.middleNode(head2);
        cout << "Middle node value: " << middle2->val << endl;

        break;
    }
    case 5: {
        ListNode* list1 = new ListNode(1);
        list1->next = new ListNode(2);
        list1->next->next = new ListNode(4);

        ListNode* list2 = new ListNode(1);
        list2->next = new ListNode(3);
        list2->next->next = new ListNode(4);

        ListNode* mergedList = sol.mergeTwoLists(list1, list2);
        cout << "Merged list: ";
        printList(mergedList);

        //--------------------------------------------------------------------

        ListNode* list3 = new ListNode();
        ListNode* list4 = new ListNode();


        ListNode* mergedList2 = sol.mergeTwoLists(list3, list4);
        cout << "Merged list: ";
        printList(mergedList2);

        //--------------------------------------------------------------------

        ListNode* list5 = new ListNode();
        ListNode* list6 = new ListNode(0);


        ListNode* mergedList3 = sol.mergeTwoLists(list5, list6);
        cout << "Merged list: ";
        printList(mergedList3);

        break;
    }
    case 6: {

        TreeNode* p1 = new TreeNode(1);
        p1->left = new TreeNode(2);
        p1->right = new TreeNode(3);

        TreeNode* q1 = new TreeNode(1);
        q1->left = new TreeNode(2);
        q1->right = new TreeNode(3);

        cout << "Trees p1 and q1 are " << (sol.isSameTree(p1, q1) ? "the same." : "not the same.") << endl;

        //----------------------------------------------

        TreeNode* p2 = new TreeNode(1);
        p2->left = new TreeNode(2);

        TreeNode* q2 = new TreeNode(1);
        q2->left = new TreeNode(2);

        cout << "Trees p2 and q2 are " << (sol.isSameTree(p2, q2) ? "the same." : "not the same.") << endl;

        //------------------------------------------------

        TreeNode* p3 = new TreeNode(1);
        p3->left = new TreeNode(2);
        p3->right = new TreeNode(1);

        TreeNode* q3 = new TreeNode(1);
        q3->left = new TreeNode(1);
        q3->right = new TreeNode(2);

        cout << "Trees p3 and q3 are " << (sol.isSameTree(p3, q3) ? "the same." : "not the same.") << endl;

        break;
    }
    case 7: {

        TreeNode* root1 = new TreeNode(4);
        root1->left = new TreeNode(2);
        root1->right = new TreeNode(7);
        root1->left->left = new TreeNode(1);
        root1->left->right = new TreeNode(3);
        root1->right->left = new TreeNode(6);
        root1->right->right = new TreeNode(9);

        TreeNode* invertedRoot1 = sol.invertTree(root1);
        cout << "Inverted Tree: ";
        sol.printTree(invertedRoot1);
        cout << endl;

        //-----------------------------------------------------

        TreeNode* root2 = new TreeNode(2);
        root2->left = new TreeNode(1);
        root2->right = new TreeNode(3);

        TreeNode* invertedRoot2 = sol.invertTree(root2);
        cout << "Inverted Tree: ";
        sol.printTree(invertedRoot2);
        cout << endl;

        //-----------------------------------------------------

        TreeNode* root3 = new TreeNode(0);
      
        TreeNode* invertedRoot3 = sol.invertTree(root3);
        cout << "Inverted Tree: ";
        sol.printTree(invertedRoot3);
        cout << endl;


        break;
    }
    case 8: {

        TreeNode* root1 = new TreeNode(3);
        root1->left = new TreeNode(9);
        root1->right = new TreeNode(20);
        root1->right->left = new TreeNode(15);
        root1->right->right = new TreeNode(7);

        cout << "Maximum depth of tree: " << sol.maxDepth(root1) << endl;

        //------------------------------------------------------

        TreeNode* root2 = new TreeNode(1);
        root2->left = new TreeNode(0);
        root2->right = new TreeNode(2);
       

        cout << "Maximum depth of tree: " << sol.maxDepth(root2) << endl;


        break;
    }
    case 9: {

        TreeNode* root1 = new TreeNode(3);
        root1->left = new TreeNode(9);
        root1->right = new TreeNode(20);
        root1->right->left = new TreeNode(15);
        root1->right->right = new TreeNode(7);

        cout << "Minimum depth of tree: " << sol.minDepth(root1) << endl;

        //------------------------------------------------------------------------

        TreeNode* root2 = new TreeNode(2);
        root2->right = new TreeNode(3);
        root2->right->right = new TreeNode(4);
        root2->right->right->right = new TreeNode(5);
        root2->right->right->right->right = new TreeNode(6);

        cout << "Minimum depth of tree: " << sol.minDepth(root2) << endl;

        break;
    }
    case 10: {

        TreeNode* root1 = new TreeNode(4);
        root1->left = new TreeNode(2);
        root1->right = new TreeNode(7);
        root1->left->left = new TreeNode(1);
        root1->left->right = new TreeNode(3);

        int val1 = 2;
        TreeNode* result1 = sol.searchBST(root1, val1);

        if (result1)
            cout << "Node found: " << result1->val << endl;
        else
            cout << "Node not found" << endl;

        //--------------------------------------------------------------


        TreeNode* root2 = new TreeNode(4);
        root2->left = new TreeNode(2);
        root2->right = new TreeNode(7);
        root2->left->left = new TreeNode(1);
        root2->left->right = new TreeNode(3);

        int val2 = 5;
        TreeNode* result2 = sol.searchBST(root2, val2);

        if (result2)
            cout << "Node found: " << result2->val << endl;
        else
            cout << "Node not found" << endl;


        break;
    }
    case 11: {

        string s1 = "(1+(2*3)+((8)/4))+1";
        string s2 = "(1)+((2))+(((3)))";
        string s3 = "()(())((()()))";

        cout << "Max depth 1: " << sol.maxDepth(s1) << endl;
        cout << "Max depth 2: " << sol.maxDepth(s2) << endl;
        cout << "Max depth 3: " << sol.maxDepth(s3) << endl;
        break;
    }
    case 12: {

        cout << sol.makeGood("leEeetcode") << endl;
        cout << sol.makeGood("abBAcC") << endl;
        cout << sol.makeGood("s") << endl;
        break;
    }
    case 13: {

        string s1 = "(()())(())";
        string s2 = "(()())(())(()(()))";
        string s3 = "()()";

        cout << "Result 1: " << sol.removeOuterParentheses(s1) << endl;
        cout << "Result 2: " << sol.removeOuterParentheses(s2) << endl;
        cout << "Result 3: " << sol.removeOuterParentheses(s3) << endl;
        break;
    }
    case 14: {

        cout << "Test Example 1: " << sol.isValid("()") << endl;
        cout << "Test Example 2: " << sol.isValid("()[]{}") << endl;
        cout << "Test Example 3: " << sol.isValid("(]") << endl;

        cout << "Custom Test 1: " << sol.isValid("") << endl;
        cout << "Custom Test 2: " << sol.isValid("()(") << endl;
        cout << "Custom Test 3: " << sol.isValid("({[]})") << endl;
        break;
    }
    case 15: {

        cout << recentCounter.ping(1) << endl;
        cout << recentCounter.ping(100) << endl;
        cout << recentCounter.ping(3001) << endl;
        cout << recentCounter.ping(3002) << endl;
        break;
    }
    default:
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
