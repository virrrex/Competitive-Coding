class robot{
    char turn(char d, char lr){
        if(d == 'E')
        {   if(lr == 'L')
                return 'N';
            else if(lr == 'R')
                return 'S';
        }
        else if(d == 'W')
        {   if(lr == 'L')
                return 'S';
            else if(lr == 'R')
                return 'N';
        }
        else if(d == 'N')
        {   if(lr == 'L')
                return 'W';
            else if(lr == 'R')
                return 'E';
        }
        else if(d == 'S')
        {   if(lr == 'L')
                return 'E';
            else if(lr == 'R')
                return 'W';
        }
    }

    String mov(int x, int y, String pos, String msg){
        int a[x][y];
        int a = pos.charAt(0) - '0';
        int b = pos.charAt(2) - '0';
        char d = pos.charAt(4);
        String res = "", end = "";
        for(int i=0; i<msg.length(); i++)
        {
            if(msg.charAt(i) == 'L')
                d = turn(d, i);
            else if(msg.charAt(i) == 'R')
                d = turn(d, i);
            else if(msg.charAt(i) == 'M')
            {
                if(d == 'E' && b == y)
                {end = "-ER"; break;}
                else if(d == 'W' && b == 0)
                {end = "-ER"; break;}
                else if(d == 'N' && a == 0)
                {end = "-ER"; break;}
                else if(d == 'S' && a == x)
                {end = "-ER"; break;}
                else
                {
                    if(d == 'E')
                        b++;
                    else if(d == 'W')
                        b--;
                    else if(d == 'N')
                        a--;
                    else if(d == 'S')
                        a++;
                }
            }
        }
        res = a + '-' + b + '-' + d + end;
        return res;
    }

    public static void main(String[] args) {
        System.out.println(mov(5,5, "3-2-E", "M L M R M R M L M"));
    }
}