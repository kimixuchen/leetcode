
import java.math.BigInteger;

public class Solution {
    public boolean isAdditiveNumber(String num) {
        int n = num.length();
        if(n<3)
        	return false;
        boolean isfind = false;
    	for(int i=0; i<n/2; ++i)
    	{
    		if(i>0 && num.charAt(0)=='0')
    			break;
    		for(int j=i+1; j<n-1; ++j)
    		{
    			if(j>i+1 && num.charAt(i+1)=='0')
    				break;
    			BigInteger n1 = new BigInteger(num.substring(0, i+1));
    			BigInteger n2 = new BigInteger(num.substring(i+1, j+1));
    			if(search(n1, n2, j+1, num))
    			{
    				isfind = true;
    				break;
    			}
    		}
    		if(isfind)
    			break;
    	}
    	
    	return isfind;
    }
    
    public boolean search(BigInteger n1, BigInteger n2, int pos, String num)
    {
    	if(pos>=num.length())
    		return true;
    	
    	n2 = n2.add(n1);
    	n1 = n2.subtract(n1);
    	if(num.substring(pos).startsWith(n2.toString()))
    	{
    		return search(n1, n2, pos+n2.toString().length(), num);
    	}
    	else
    		return false;
    	
    	
    }
}