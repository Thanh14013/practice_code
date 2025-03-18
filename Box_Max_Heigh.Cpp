#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Cấu trúc biểu diễn một hộp
struct Box
{
    int width;
    int depth;
    int height;
};

// Cấu trúc biểu diễn một cách xếp của hộp
struct BoxRotation
{
    int width;
    int depth;
    int height;
    // int index; // Có thể thêm index nếu cần theo dõi hộp gốc
};

int maxHeightBoxStack(vector<Box> &boxes)
{
    int n = boxes.size();
    // Bước 1: Tạo ra tất cả các hướng có thể xếp của mỗi hộp
    vector<BoxRotation> rotations;

    for (int i = 0; i < n; i++)
    {
        // Cách 1: đáy là (width, depth)
        rotations.push_back({max(boxes[i].width, boxes[i].depth),
                             min(boxes[i].width, boxes[i].depth),
                             boxes[i].height});

        // Cách 2: đáy là (width, height)
        rotations.push_back({max(boxes[i].width, boxes[i].height),
                             min(boxes[i].width, boxes[i].height),
                             boxes[i].depth});

        // Cách 3: đáy là (depth, height)
        rotations.push_back({max(boxes[i].depth, boxes[i].height),
                             min(boxes[i].depth, boxes[i].height),
                             boxes[i].width});
    }

    // Bước 2: Sắp xếp các hộp theo thứ tự giảm dần của diện tích đáy
    sort(rotations.begin(), rotations.end(), [](const BoxRotation &a, const BoxRotation &b)
         { return a.width * a.depth > b.width * b.depth; });

    // Bước 3: Áp dụng thuật toán Longest Increasing Subsequence biến thể
    int totalRotations = rotations.size();
    vector<int> dp(totalRotations);

    for (int i = 0; i < totalRotations; i++)
    {
        dp[i] = rotations[i].height; // Khởi tạo với chiều cao của hộp hiện tại

        for (int j = 0; j < i; j++)
        {
            // Nếu có thể đặt hộp i lên trên hộp j
            if (rotations[j].width > rotations[i].width &&
                rotations[j].depth > rotations[i].depth)
            {
                // Cập nhật chiều cao lớn nhất có thể
                dp[i] = max(dp[i], dp[j] + rotations[i].height);
            }
        }
    }

    // Trả về chiều cao lớn nhất có thể đạt được
    return *max_element(dp.begin(), dp.end());
}

// Hàm thiết lập các hộp từ dữ liệu đầu vào
vector<Box> createBoxes(const vector<vector<int>> &dimensions)
{
    vector<Box> boxes;
    for (const auto &dim : dimensions)
    {
        boxes.push_back({dim[0], dim[1], dim[2]});
    }
    return boxes;
}

int main()
{
    // Ví dụ minh họa
    vector<vector<int>> dimensions = {
        {4, 6, 7},
        {1, 2, 3},
        {4, 5, 6},
        {10, 12, 32}};

    vector<Box> boxes = createBoxes(dimensions);

    int maxHeight = maxHeightBoxStack(boxes);
    cout << "Chiều cao tối đa có thể đạt được: " << maxHeight << endl;

    return 0;
}