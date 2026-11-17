# Code Review Report: UVa 494 - Kindergarten Counting Game

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 494
- **Problem Title:** Kindergarten Counting Game
- **Problem Link:** https://onlinejudge.org/external/4/494.pdf
- **Language / Version:** C++
- **Submission Result:** Wrong Answer（共提交 9 次，2026-11-03）
- **Source Code (Initial/Fail):** [src/s1151536-UVa494_fail.cpp](./src/s1151536-UVa494_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/s1151536-UVa494.cpp](./src/s1151536-UVa494.cpp)（最新一次提交，尚未 AC）
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
int main(){
	string s="";
	while(getline(cin, s)){
		stringstream ss(s);
		long long i=0;
		string voc="";
		while(ss >> voc){
			long long notAlp=0, alp=0;
			bool check=true;
			for (int i=0; i<voc.size(); i++){
				if((int('a')<=int(voc[i]) && int('z')>=int(voc[i])) || (int('A')<=int(voc[i]) && int('Z')>=int(voc[i]))){
					continue;
				}else{
					if(i!=voc.size()-1){
						check = false;
						break;
					}
				}
			}
			if(check)i++;
		}
		cout << i << endl;
	}
	return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- 題目定義的「單字」是**連續的英文字母**，任何非字母字元（空白、標點、數字、撇號、連字號）都是分隔。程式卻以空白切出 token，再檢查 token 是否「只有最後一個字元可以不是字母」，這和題意不同。
- 例如 `don't` 應算 2 個字（don、t），`hello-world` 應算 2 個，`a1b` 應算 2 個，程式都輸出 0。
- 最新版只多加了「單一非字母字元不算」的判斷，沒有處理上述情況；9 次提交都在修補同一個錯誤的方法。

### Latest Code（尚未 AC）

```cpp
#include <bits/stdc++.h>
using namespace std;
int main(){
	string s="";
	while(getline(cin, s)){
		stringstream ss(s);
		long long i=0;
		string voc="";
		while(ss >> voc){
			long long notAlp=0, alp=0;
			bool check=true;
			for (int i=0; i<voc.size(); i++){
				if((int('a')<=int(voc[i]) && int('z')>=int(voc[i])) || (int('A')<=int(voc[i]) && int('Z')>=int(voc[i]))){
					continue;
				}else{
					if(voc.size()==1){
						check = false;
						break;
					}
					if(i!=voc.size()-1){
						check = false;
						break;
					}
				}
			}
			if(check && voc.size()>=1)i++;
		}
		cout << i << endl;
	}
	return 0;
}
```

**How to fix（AI 診斷，請讀懂後改寫成自己的話）:**

- **尚未 AC。** 修正方向（AI 建議，請自行實作後重新提交）：
- 逐字元掃描整行，用一個布林值記錄「前一個字元是不是字母」；當目前字元是字母（`isalpha`）而前一個不是時，字數 +1。不需要 stringstream。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | Meep Meep!<br>I tot I taw a putty tat.<br>Shsssssssssh ... I am hunting wabbits. Heh Heh Heh Heh ...<br>Alright, I am going home. | 2<br>7<br>9<br>5 | 2<br>7<br>9<br>5 | 題目範例（剛好通過） |
| Edge | don't<br>hello-world<br>a1b | 2<br>2<br>2 | 0<br>0<br>0 | 非字母字元在單字中間 |
| Boundary | ... ,,, !!! | 0 | 0 | 只有標點 |

⚠️ 有 1 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Latest / To-do |
|---|---|---|
| Logic | 空白切 token + 檢查 | （待修正） |
| Edge Cases | 字中間的非字母 | （待修正） |
| Output Handling | 同 | （待修正） |
| Complexity | O(行長) | O(行長) |
| Code Quality | 重複修補同一方法 | （待修正） |

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
| UVa 494 / Kindergarten Counting Game | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
