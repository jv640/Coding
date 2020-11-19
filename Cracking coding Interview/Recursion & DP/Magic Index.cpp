/*
  Description : A magic index in an array A [e ... n -1] is defined to be an index such that A[ i] = i. 
                Given a sorted array of distinct integers, write a method to find a magic index, if one exists, in array A.
*/

// Code
int magicindex(vector<int> A){
  if (start <= end) {
			int mid = (start + end) / 2;
			if (mid == A[mid]) // check for magic index.
				return mid;
			if (mid > A[mid]) { // If mid>A[mid] means fixed point might be on
								// the right half of the array
				return search(A, mid + 1, end);
			} else {// If mid<A[mid] means fixed point might be on
				// the left half of the array
				return search(A, start, mid - 1);
			}
		}
		return -1;
}
