package t2;

import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {
	
	PriorityQueue<Integer> minHeap = new PriorityQueue<>();
    PriorityQueue<Integer> maxHeap = new PriorityQueue<>(
    		new Comparator<Integer>() {
    			public int compare(Integer i1, Integer i2){
    				return i2.compareTo(i1);
    			}
			});
	
    public double[] medianSlidingWindow(int[] nums, int k) {
        int n = nums.length;
    	double[] ret = new double[n-k+1];
        
        for(int i=0; i<=n; ++i){
        	if(i>=k){
        		ret[i-k] = getMedian();
        		remove(nums[i-k]);
        	}
        	if(i<n){
        		add(nums[i]);
        	}
        }
        return ret;
    }
    
    public double getMedian(){
    	if(minHeap.size()==maxHeap.size()){
    		return (minHeap.peek()*1.0+maxHeap.peek())/2;
    	}else{
    		return maxHeap.peek();
    	}
    }
    
    public void remove(int num){
    	if(num>maxHeap.peek()){
    		minHeap.remove(num);
    	}else{
    		maxHeap.remove(num);
    	}
    	
    	if(minHeap.size()>maxHeap.size()){
    		maxHeap.add(minHeap.poll());
    	}
    	if(maxHeap.size()-minHeap.size()>1){
    		minHeap.add(maxHeap.poll());
    	}
    }
    
    public void add(int num){
    	if(maxHeap.size()>0 && num>maxHeap.peek()){
    		minHeap.add(num);
    	}else{
    		maxHeap.add(num);
    	}
    	
    	if(minHeap.size()>maxHeap.size()){
    		maxHeap.add(minHeap.poll());
    	}
    	if(maxHeap.size()-minHeap.size()>1){
    		minHeap.add(maxHeap.poll());
    	}
    }
}
