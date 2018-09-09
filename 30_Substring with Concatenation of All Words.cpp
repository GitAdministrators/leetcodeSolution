class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		int wlen = words.size();
		int slen = s.size();
		int maxw = 0;
		std::unordered_map<string, int> umap;
		for (int i = 0; i<wlen; i++)
		{
			umap[words[i]]++;
			maxw = maxw> words[i].size() ? maxw : words[i].size();
		}

		int index = 0;
		int count = 0;
		int spoint = 0;
		int next = 0;
		set<int> res;
		for (int i = 0; i<slen; i++)
		{
			if (i - index < maxw)
			{
				string tmpword = s.substr(index, i - index + 1);
				if (umap.find(tmpword) != umap.end())
				{
					umap[tmpword]--;
					if (umap[tmpword] <0)
					{
						initumap(umap, words);
						i = next-1;
						index = next;
						count = 0;
					}
					else
					{
						if (count == 0)
						{
							spoint = index;
							next++;
						}
						index = i + 1;
						count++;
						if (count == wlen)
						{
							res.insert(spoint);
							i = next-1;
							index = next;
							initumap(umap, words);
							count = 0;
						}
					}
				}
			}
			else
			{
				initumap(umap, words);
				spoint++;
				index = spoint;
				i = index-1;
				count = 0;
			}
		}
        return vector<int>(res.begin(),res.end());
    }
    void initumap(unordered_map<string,int>& umap ,vector<string>& words)
    {
        for(auto it = umap.begin();it!=umap.end();it++)
        {
            it->second = 0;
        }
        for(int i = 0 ; i<words.size(); i++)
        {
            umap[words[i]]++;
        }
    }
};
