int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max = 0;

    while (left < right) {
        int minHeight;

        if (height[left] < height[right])
            minHeight = height[left];
        else
            minHeight = height[right];

        int width = right - left;
        int area = minHeight * width;

        if (area > max)
            max = area;

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return max;
}