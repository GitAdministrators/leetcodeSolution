class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<std::pair<string, int> > res;
		for (int i = 0; i<2 * n; i++)
		{
			generate(res,i,n);
		}

		vector<string> svec;
		for (int i = 0; i<res.size(); i++)
		{
			svec.push_back(res[i].first);
		}

		return svec;
	}

	void generate(vector<std::pair<string, int> >& vec,int count, int n)
	{
		if (vec.empty())
		{
			vec.push_back(std::make_pair("(", 1));
		}
		else
		{
			vector<std::pair<string, int> > tmpvec;
			for (int i = 0; i<vec.size(); i++)
			{
				if(vec[i].first.back() == '(')
                {
                    if(vec[i].second >=n)
                    {
                        tmpvec.push_back(std::make_pair(vec[i].first + ")" , vec[i].second));
                    }
                    else
                    {
                        if( count< 2* vec[i].second)
                        {
                            tmpvec.push_back(std::make_pair(vec[i].first + ")",vec[i].second)); 
                        }
                        tmpvec.push_back(std::make_pair(vec[i].first + "(" , vec[i].second + 1));
                    }
                }
                else
                {   if(vec[i].second >=n)
                    {
                     tmpvec.push_back(std::make_pair(vec[i].first + ")",vec[i].second));
                    }
                    else
                    {
                         if(count < 2* vec[i].second)
                        {
                            tmpvec.push_back(std::make_pair(vec[i].first + ")",vec[i].second)); 
                        }
                        tmpvec.push_back(std::make_pair(vec[i].first + "(" , vec[i].second + 1));
                    }
                    
                }
			}
			vec = std::move(tmpvec);
		}
	}
};
