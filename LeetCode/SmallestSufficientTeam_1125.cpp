/*
In a project, you have a list of required skills req_skills, and a list of people. The ith person people[i] contains a list of skills that the person has.

Consider a sufficient team: a set of people such that for every required skill in req_skills, there is at least one person in the team who has that skill. We can represent these teams by the index of each person.

For example, team = [0, 1, 3] represents the people with skills people[0], people[1], and people[3].
Return any sufficient team of the smallest possible size, represented by the index of each person. You may return the answer in any order.

It is guaranteed an answer exists.

 

Example 1:

Input: req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
Output: [0,2]
Example 2:

Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
Output: [1,2]
 

Constraints:

1 <= req_skills.length <= 16
1 <= req_skills[i].length <= 16
req_skills[i] consists of lowercase English letters.
All the strings of req_skills are unique.
1 <= people.length <= 60
0 <= people[i].length <= 16
1 <= people[i][j].length <= 16
people[i][j] consists of lowercase English letters.
All the strings of people[i] are unique.
Every skill in people[i] is a skill in req_skills.
It is guaranteed a sufficient team exists.
*/


class Solution {
 public:
  vector<int> smallestSufficientTeam(vector<string>& req_skills,
                                     vector<vector<string>>& people) {
    const int n = req_skills.size();
    const int nSkills = 1 << n;
    unordered_map<string, int> skillToId;
    // dp[i] := the minimum people's indices to cover skillset of mask i
    unordered_map<int, vector<int>> dp;
    dp.reserve(nSkills);  // Avoid rehash
    dp[0] = {};

    for (int i = 0; i < n; ++i)
      skillToId[req_skills[i]] = i;

    auto getSkill = [&](const vector<string>& person) {
      int mask = 0;
      for (const string& skill : person)
        if (const auto it = skillToId.find(skill); it != skillToId.cend())
          mask |= 1 << it->second;
      return mask;
    };

    for (int i = 0; i < people.size(); ++i) {
      const int currSkill = getSkill(people[i]);
      for (const auto& [mask, indices] : dp) {
        const int newSkillSet = mask | currSkill;
        if (newSkillSet == mask)  // Adding people[i] doesn't increase skill set
          continue;
        if (!dp.count(newSkillSet) ||
            dp[newSkillSet].size() > indices.size() + 1) {
          dp[newSkillSet] = indices;
          dp[newSkillSet].push_back(i);
        }
      }
    }

    return dp[nSkills - 1];
  }
};



Runtime
47ms
Beats 67.82% of users with C++
Memory
21.91MB
Beats 55.32% of users with C++