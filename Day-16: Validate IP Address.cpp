class Solution {
public:
    string validIPAddress(string IP) {
        int cdot = 0, ccolon = 0;
        for(int i=0; i<IP.length(); i++)
        {
            if(IP[i]=='.')
                cdot++;
            if(IP[i]==':')
                ccolon++;
        }
        if(cdot==3)
        {
            vector<string> ar;
            stringstream check1(IP);
            string temp;
            while(getline(check1, temp, '.'))
                ar.push_back(temp);
            bool val = true;
            if(ar.size()!=4)
                val = false;
            else
            {
                for(int i=0; i<4; i++)
                {
                    if((ar[i][0]=='0' && ar[i].length()>1) || ar[i].length()<1 || ar[i].length()>3)
                    {
                        val = false;
                        break;
                    }
                    int s = 0;
                    for(int j=0; j<ar[i].length(); j++)
                    {
                        if(ar[i][j]>'9' || ar[i][j]<'0')
                        {
                            val = false;
                            break;
                        }
                        s=s*10+ar[i][j]-'0';
                    }
                    if(s>255)
                    {
                        val = false;
                        break;
                    }
                }
            }
            if(val)
                return "IPv4";
        }
        if(ccolon==7)
        {
            vector<string> ar;
            stringstream check1(IP);
            string temp;
            while(getline(check1, temp, ':'))
                ar.push_back(temp);
            bool val = true;
            if(ar.size()!=8)
                val = false;
            else
            {
                for(int i=0; i<8; i++)
                {
                    if((ar[i][0]=='0' && ar[i].length()>4) || ar[i].length()<1 || ar[i].length()>4)
                    {
                        val = false;
                        break;
                    }
                    for(int j=0; j<ar[i].length(); j++)
                    {
                        if(ar[i][j]<'0' || (ar[i][j]>'9' && ar[i][j]<'A') || (ar[i][j]>'F' && ar[i][j]<'a') || ar[i][j]>'f')
                        {
                            val = false;
                            break;
                        }
                    }
                }
            }
            if(val)
                return "IPv6";
        }
        return "Neither";
    }
};