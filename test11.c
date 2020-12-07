#define _CRT_SECURE_NO_WARNINGS 1
//题目等会补
//1 3 4 3 5 3      3
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。


int removeElement(int* nums, int numsSize, int val)
{
	int src = 0;
	int dst = 0;
	while (src < numsSize)
	{
		if (nums[src] != val)
		{
			nums[dst] = nums[src];
			src++;
			dst++;
		}
		else
		{
			src++;
		}
	}
	return dst;
}


//给定一个（去重）
//给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。


int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	int prev = 0, cur = 1, dst = 0;
	while (cur < numsSize) //用cur来判断，因为他越界了
	{
		if (nums[prev] != nums[cur])
		{
			nums[dst] = nums[prev];
			prev++;
			dst++;
			cur++;
		}
		else
		{
			prev++;
			cur++;
		}
	}
	//此时prev和cur的值是不相等的，但是上面你只返回了prev的值，最后一个cur值也是需要返回的
	nums[dst] = nums[prev];
	dst++;
	return dst;
}




//
//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。例如，如果 X = 1231，那么其数组形式为 [1, 2, 3, 1]。
//给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。
//案例：
//输入：A = [1, 2, 0, 0], K = 34
//输出：[1, 2, 3, 4]
//解释：1200 + 34 = 1234

int* addToArrayForm(int* A, int ASize, int K, int* returnSize)
{
	//计算k是多少位的
	int KSize = 0;
	int kNum = K;
	while (kNum)
	{
		KSize++;
		kNum /= 10;
	}
	int len = ASize > KSize ? ASize : KSize;
	int* retArr = (int*)malloc(sizeof(int)*(len+1));

	//A []
	//K
	int Ai = ASize - 1;
	int reti = 0;
	int nextNum = 0;//进位
	while (len--)
	{
		int a = 0;
		if (Ai >= 0) // A的数组短，会先走完
		{
			a = A[Ai];
			Ai--;
		}
		int ret = A[Ai] + K % 10 + nextNum;
		Ai--;
		K /= 10;
		if (ret > 9)
		{
			ret -= 10;
			nextNum = 1;
		}
		else
		{
			nextNum = 0;
		}
		retArr[reti] = ret;
		reti++;
	}
	if (nextNum == 1)
	{
		retArr[reti] = 1;
		reti++;
	}
	//逆置
	int left = 0;
	int right = reti - 1;
	while (left < right)
	{
		int tmp = left;
		left = right;
		right = tmp;
		left++;
		right--;
	}
	*returnSize = reti;
	return retArr;
}
