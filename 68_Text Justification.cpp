class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		auto it = words.begin();
		while (it != words.end())
		{
			string tmp("");
			auto potit = it;
			int tmplen = 0;
			int wordlen = 0;
			while (it != words.end() && tmplen < maxWidth)
			{
				if (tmplen == 0)
				{
					tmplen += (*it).size();
					wordlen += (*it).size();
                    if(tmplen == maxWidth) break;
					it++;
				}
				else if (tmplen + (*it).size() + 1 == maxWidth)
				{
					tmplen += (*it).size() + 1;
					wordlen += (*it).size();
					break;
				}
				else if (tmplen + (*it).size() + 1 < maxWidth)
				{
					tmplen += ((*it).size() + 1);
					wordlen += (*it).size();
					it++;
				}
				else
				{
					it--;
					break;
				}
			}

			if (it == words.end())
			{
				while (potit<it)
				{
					tmp += *potit + " ";
					potit++;
				}
				int needfit = maxWidth - tmp.size();
				while (needfit<0)
				{
					tmp.pop_back();
					needfit++;
				}
				tmp += string(needfit, ' ');
				res.push_back(tmp);
				break;
			}



			if (tmplen == maxWidth)
			{
				while (potit<it)
				{
					tmp += *potit + " ";
					potit++;
				}
				tmp += *it;
				res.push_back(tmp);
			}
			else if (tmplen<maxWidth)
			{
				int dis = it - potit;
				int spacecnt = maxWidth - wordlen;
				if (dis == 0 || dis == 1)
				{
					tmp += *potit + string(spacecnt, ' ');
					if (potit != it) tmp += *it;
				}
				else
				{
					int ever = spacecnt / (dis);
					int more = spacecnt % (dis);
					while (potit<it)
					{
						int im = more>0 ? 1 : 0;
						tmp += *potit + string(ever + im, ' ');
						more--;
						potit++;
					}
					tmp += *it;

				}
				res.push_back(tmp);
			}
			it++;
		}
		return res;
	}
};
