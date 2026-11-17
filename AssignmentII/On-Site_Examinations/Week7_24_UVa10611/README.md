# Code Review Report: UVa 10611 - The Playboy Chimp

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 10611
- **Problem Title:** The Playboy Chimp
- **Problem Link:** https://onlinejudge.org/external/106/10611.pdf
- **Language / Version:** C++
- **Submission Result:** Wrong Answer（共提交 6 次，2026-10-20）
- **Source Code (Initial/Fail):** [src/UVa10611_fail.cpp](./src/UVa10611_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/UVa10611_latest.cpp](./src/UVa10611_latest.cpp)（最新一次提交，尚未 AC）
- **Review Date:** 2026-11-17

## 2. Problem Statement in My Own Words

> ✍️ **TODO（請用自己的話完成）**：輸入是什麼？輸出是什麼？主要規則與限制？核心任務？（不要複製原題）

## 3. Thinking Logic and Solution Strategy

### Initial Thoughts

> ✍️ **TODO（請用自己的話完成）**：第一個想法是什麼？一開始注意到哪些困難？為什麼初版不夠？

### Final Strategy

> ✍️ **TODO（請用自己的話完成）**：最後用了什麼方法？為什麼可行？考慮了哪些邊界情況？

### Complexity Analysis

- **Time Complexity:**
- **Space Complexity:**

> ✍️ **TODO（請用自己的話完成）**：說明為何符合題目限制。

## 4. Pseudocode

> ✍️ **TODO（請用自己的話完成）**：依照你的最終程式寫出主要步驟。

```text
START
1.
2.
3.
END
```

## 5. Fail Code vs Correct Code

### Fail Code

```cpp
#include <bits/stdc++.h>
using namespace std;
int l, r;
int n, m, buf;
vector<int> lady;
int bsearch(int x){
	l=0; r=n-1;
	int mid=0;
	while(l<r){
		mid = (l+r)/2;
		if(lady[mid] == x){
			l = mid-1;
			r = mid+1;
			return 0;
		}
		if(lady[mid] > x){
			r = mid - 1; 
		}else if(lady[mid] < x){
			l = mid + 1;
		}
	}
	l=mid;
	r=mid+1;
	return 0;
}

int main(){
	cin >> n;
	if(n==0){
		cout << "X X" << endl;
		return 0;
	}
	for(int i=0; i<n; i++){
		cin >> buf;
		lady.push_back(buf);
	}
	sort(lady.begin(), lady.end());
	cin >> m;
	for(int i=0; i<m; i++){
		int buf=0;
		cin >> buf;
		if(buf < lady[0]){
			cout << "X " << lady[0] << endl;
			continue; 
		}else if(buf > lady[n-1]){
			cout << lady[n-1] << " X" << endl;
			continue; 
		}
		bsearch(buf);
		cout << lady[l] << " " << lady[r] << endl;
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 自寫二分搜尋在找到相等值時設 `l = mid-1, r = mid+1`：有重複身高時答案不正確，且 `mid = 0` 時 `l = -1` 會越界。
- 迴圈結束後直接 `l = mid; r = mid+1`，不保證 lady[l] < x < lady[r]。
- 查詢值等於最矮者時（例如 x = lady[0]），應輸出 `X` 卻輸出了 lady[l]。
- 最後一版把 int 改成 long long 並沒有處理到真正的錯誤。

### Latest Code（尚未 AC）

```cpp
#include <bits/stdc++.h>
using namespace std;
int l, r;
int n, m, buf;
vector<long long> lady;
int bsearch(long long x){
	l=0; r=n-1;
	int mid=0;
	while(l<r){
		mid = (l+r)/2;
		if(lady[mid] == x){
			l = mid-1;
			r = mid+1;
			return 0;
		}
		if(lady[mid] > x){
			r = mid - 1; 
		}else if(lady[mid] < x){
			l = mid + 1;
		}
	}
	l=mid;
	r=mid+1;
	return 0;
}

int main(){
	cin >> n;
	if(n==0){
		cout << "X X" << endl;
		return 0;
	}
	for(int i=0; i<n; i++){
		cin >> buf;
		lady.push_back(buf);
	}
	sort(lady.begin(), lady.end());
	cin >> m;
	for(int i=0; i<m; i++){
		long long buf=0;
		cin >> buf;
		if(buf < lady[0]){
			cout << "X " << lady[0] << endl;
			continue; 
		}else if(buf > lady[n-1]){
			cout << lady[n-1] << " X" << endl;
			continue; 
		}
		bsearch(buf);
		cout << lady[l] << " " << lady[r] << endl;
	}
	return 0;
}
```

**How to fix（AI 診斷，請讀懂後改寫成自己的話）:**

- **尚未 AC。** 修正方向（AI 建議，請自行實作後重新提交）：
- 排序後用 `lower_bound(x)` 找第一個 ≥ x 的位置 i，用 `upper_bound(x)` 找第一個 > x 的位置 j：左邊答案是 `i>0 ? lady[i-1] : X`，右邊答案是 `j<n ? lady[j] : X`。這樣自動處理重複值與兩端邊界。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 4<br>1 4 5 7<br>4<br>4 6 8 10 | 1 5<br>5 7<br>7 X<br>7 X | 1 5<br>5 7<br>7 X<br>7 X | 題目範例 |
| Edge | 5<br>1 2 2 2 3<br>1<br>2 | 1 3 | 2 2 | 查詢值有重複 |
| Boundary | 4<br>1 4 5 7<br>1<br>1 | X 4 | 4 5 | 查詢值等於最矮者 |

⚠️ 有 2 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Latest / To-do |
|---|---|---|
| Logic | 自寫二分搜尋 | （待修正） |
| Edge Cases | 重複值、兩端邊界錯誤 | （待修正） |
| Output Handling | 同 | （待修正） |
| Complexity | O(log n)/查詢 | O(log n)/查詢 |
| Code Quality | 全域變數 l、r 傳結果 | （待修正） |

### Reflection

- **Root cause:**
- **Lesson learned:**
- **Next action:**

> ✍️ **TODO（請用自己的話完成）**：根據上面的診斷，寫下你自己的反思。

## 8. AI Usage Disclaimer

- AI tools, if used, were used only to support learning, such as clarifying concepts or reviewing explanations.
- I independently understood, verified, and completed the solution and reflection in this report.

### AI Usage Record

| Problem ID / Title | AI Tool Used | How It Was Used | Verification Performed Independently |
|---|---|---|---|
| UVa 10611 / The Playboy Chimp | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
