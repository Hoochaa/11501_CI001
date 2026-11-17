# Code Review Report: UVa 11984 - A Change in Thermal Unit

## 1. Problem Information

- **Platform:** UVa（課程 Online Judge 140.138.144.29）
- **Problem ID:** 11984
- **Problem Title:** A Change in Thermal Unit
- **Problem Link:** https://onlinejudge.org/external/119/11984.pdf
- **Language / Version:** C++
- **Submission Result:** Wrong Answer（共提交 27 次，2026-09-08）
- **Source Code (Initial/Fail):** [src/s1151536-UVa11984_fail.cpp](./src/s1151536-UVa11984_fail.cpp)（Wrong Answer）
- **Source Code (Final/Accepted):** [src/s1151536-UVa11984.cpp](./src/s1151536-UVa11984.cpp)（最新一次提交，尚未 AC）
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
#include<iostream>
using namespace std;
int main(){
	int c=0;
  	cin >> c;
  	long long C=0, F=0;
    float D=0;
  	for (int i=0; i<c; i++){
        cin >> C >> F;
    	float ans=0;
        D = C/5*9+32;
        D += F;
        D = (D-32)/9*5;
        int a = D*100;
        if(D-a>=0.5){
            a += 1;
        }
        ans = a *0.01;
      	cout << "Case " << i+1 << ": " << ans << endl;
    }
  return 0;
}
```

**Why it failed（AI 診斷，請讀懂後改寫成自己的話）:**

- `C/5*9`：`C` 是 `long long`，`C/5` 先做整數除法會把小數截掉（例如 C=1 時變成 0）。
- 輸出沒有用 `fixed << setprecision(2)`，`100` 會印成 `100` 而不是 `100.00`。
- 自己用 `int a = D*100` 做四捨五入，再乘 `0.01` 轉回 `float`，會產生 `55.55` 這類誤差。
- 前 6 次為 CE、之後 20 次 WA 且多次內容幾乎相同，建議每次重送前先用範例自己測。

### Latest Code（尚未 AC）

```cpp
#include<iostream>
using namespace std;
int main(){
	int c=0;
  	cin >> c;
  	long long C=0, F=0;
    float D=0;
  	for (int i=0; i<c; i++){
        cin >> C >> F;
        D = C/5*9+32;
        D += F;
        D = (D-32)/9*5;
        int a = D*100;
        if(D-a>=0.5){
            a += 1;
        }
        float ans = a *0.01;
      	cout << "Case " << i+1 << ": " << ans << endl;
    }
  return 0;
}
```

**How to fix（AI 診斷，請讀懂後改寫成自己的話）:**

- **尚未 AC。** 修正方向（AI 建議，請自行實作後重新提交）：
   1. 換算時先轉成浮點：`C * 9.0 / 5 + 32`。
   2. 加上 d 後換回攝氏：`(F - 32) * 5.0 / 9`。
   3. 用 `double` 並以 `fixed << setprecision(2)` 輸出，不需要自己四捨五入。

## 6. Test Evidence

以下測試由 AI 將程式碼在 g++ 13 上實際編譯執行取得（Actual Result 為程式真實輸出）。

| Test Category | Input Summary | Expected Result | Actual Result | Purpose |
|---|---|---|---|---|
| Normal | 2<br>100 0<br>0 100 | Case 1: 100.00<br>Case 2: 55.56 | Case 1: 100<br>Case 2: 55.55 | 題目範例 |
| Edge | 1<br>1 1 | Case 1: 1.56 | Case 1: 0.55 | C 不是 5 的倍數（整數除法） |
| Boundary | 1<br>0 0 | Case 1: 0.00 | Case 1: 0 | 輸出需固定兩位小數 |

⚠️ 有 3 筆測試的實際結果與預期不符，詳見第 5 節診斷。

## 7. Difference and Reflection

### Key Differences

| Item | Fail Code | Latest / To-do |
|---|---|---|
| Logic | C/5 整數除法 | （待修正） |
| Edge Cases | 未考慮非 5 倍數 | （待修正） |
| Output Handling | 缺少 setprecision(2) | （待修正） |
| Complexity | O(1)/筆 | O(1)/筆 |
| Code Quality | 手動四捨五入、float 誤差 | （待修正） |

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
| UVa 11984 / A Change in Thermal Unit | Claude (Anthropic) | 從 OJ 整理提交紀錄、診斷失敗原因、產生並執行測試資料、填寫第 1、5、6 節與第 7 節差異表 | ✍️ TODO：寫下你自己做了哪些驗證 |

## 9. Final Re-review Checklist

- [ ] The problem information, source-code links, and submission result are accurate.
- [ ] The problem statement and reflection are written in my own words.
- [ ] The strategy, pseudocode, and complexity analysis match the final code.
- [ ] The fail-code explanation identifies a reproducible failing case or clearly explains what was incomplete.
- [ ] The test table includes actual evidence for normal, boundary, and edge cases.
- [ ] The AI usage record is complete and accurate.
