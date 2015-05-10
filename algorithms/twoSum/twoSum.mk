
- 第一種解法是直接跑兩次 for loop
- 第二種解法是利用 hash table，把 targe - num[i] 的差值存入 table，這個值就是要找的另一個 number。用 loop 往下找 num[i]，
，檢查 num[i] 是否存在於 table 中。
