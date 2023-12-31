//
//  ListNode.hpp
//  LeetCodeCPlus
//
//  Created by Peng on 2023/7/2.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>

inline ListNode * ListNodeCreate(std::vector<int> nums) {
    if (nums.empty()) { return nullptr; }
    size_t size = nums.size();
    ListNode * l = new ListNode();
    ListNode * temp = l;
    for (int i = 0; i < size; i ++) {
        temp->next = new ListNode(nums[i]);
        temp = temp->next;
    }
    return l->next;
};

#endif /* ListNode_hpp */
