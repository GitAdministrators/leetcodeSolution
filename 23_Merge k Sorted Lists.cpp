/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int len = lists.size();
		vector<int> helpIntVec(len, INT_MAX);
		int helpcount = 0;
		std::multimap<int, int> helpMap;

		ListNode* pNode = new ListNode(0);
		ListNode* tmp = pNode;

		for (int i = 0; i<lists.size(); i++)
		{
			if (lists[i] != NULL)
			{
				helpIntVec[i] = lists[i]->val;
				helpMap.insert(std::make_pair(lists[i]->val, i));
			}
			else
			{
				helpcount++;
			}
		}
		sort(helpIntVec.begin(), helpIntVec.end());

		ListNode* helplist = new ListNode(0);
		ListNode* first = helplist;
		for (int i = 0; i<helpIntVec.size(); i++)
		{
			first->next = new ListNode(helpIntVec[i]);
			first = first->next;
		}
		helplist = helplist->next;

		while (helpcount<len)
		{
			std::multimap<int, int>::iterator it = helpMap.find(helplist->val);
			if (it != helpMap.end())
			{
				int index = it->second;
				tmp->next = new ListNode(lists[index]->val);
				tmp = tmp->next;
				if (lists[index]->next != NULL)
				{
					lists[index] = lists[index]->next;

					helpMap.erase(it);
					helpMap.insert(std::make_pair(lists[index]->val, index));

					//deal helplist
					helplist = helplist->next;
					if (lists[index] != NULL)
					{
						ListNode* t = helplist;
						ListNode* tb = new ListNode(0);

						for (int i = 0; i<len; i++)
						{
							if (helplist == NULL)
							{
								helplist = new ListNode(lists[index]->val);
							}
							else if (t == NULL)
							{
								tb->next = new ListNode(lists[index]->val);
							}
							else
							{
								if (t->val >= lists[index]->val)
								{
									if(tb->next == NULL)
									{
										ListNode* newhelplist = new ListNode(lists[index]->val);
										newhelplist->next = helplist;
										helplist = newhelplist;
										break;
									}
									else
									{

										tb->next = new ListNode(lists[index]->val);
										tb = tb->next;
										tb->next = t;
										break;
									}
								}
								else
								{
									tb->next = t;
									t = t->next;
									tb = tb->next;
								}
							}
						}
					}
				}
				else
				{
					lists[index] = lists[index]->next;
					helpMap.erase(it);
					//deal helplist
					helplist = helplist->next;
					helpcount++;
				}
			}
		}
		return pNode->next;
	}
};
