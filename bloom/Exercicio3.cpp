int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime){
	vector <pair <int, int>> ps;
	int totalPlantTime = 0, res = 0;

	for (int i = 0; i < plantTime.size(); i++)
		ps.push_back({plantTime[i], growTime[i]});

	sort(ps.begin(), ps.end(), [](auto &left, auto &right) {
		return right.second < left.second;
	});

	for (auto p : ps) {
		totalPlantTime += p.first;
		res = max(res, totalPlantTime + p.second);
	}
	
	return res;
}
