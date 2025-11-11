long long merge(vector<int>& d, int l, int m, int r, int diff) {
        long long count = 0;
        
        int i = l;
        for (int j = m + 1; j <= r; ++j) {
            while (i <= m && d[i] <= (long long)d[j] + diff)
                i++;
            
            count += (i - l);
        }

        vector<int> temp;
        i = l;            
        int j = m + 1;   

        while (i <= m && j <= r) {
            if (d[i] <= d[j])
                temp.emplace_back(d[i++]);
            else
                temp.emplace_back(d[j++]);
        }

        while (i <= m)
            temp.emplace_back(d[i++]);

        while (j <= r)
            temp.emplace_back(d[j++]);

        for (int k = 0; k < temp.size(); ++k)
            d[l + k] = temp[k];

        return count;
    }

long long mergeSort(vector<int>& d, int l, int r, int diff) {
        if (l >= r)
            return 0;

        int m = l + (r - l) / 2;
        
        long long count = 0;
        
        count += mergeSort(d, l, m, diff);
        count += mergeSort(d, m + 1, r, diff);
        count += merge(d, l, m, r, diff);
        
        return count;
    }

long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        if (n < 2)
            return 0;

        vector<int> d(n);
        for (int i = 0; i < n; ++i)
            d[i] = nums1[i] - nums2[i];

        return mergeSort(d, 0, n - 1, diff);
}
