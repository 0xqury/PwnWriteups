# Dreamhack - shell_basic

## 🔐 문제 설명

간단한 바이너리 파일에서 셸코드를 입력받고 이를 실행하는 구조를 가진 문제다.  
단, `execve()`와 `execveat()` 시스템 콜은 `seccomp` 필터로 막혀 있어 쉘 실행이 불가능하다.

따라서 파일을 직접 열어서 내용을 출력하는 ORW(Open-Read-Write) 시나리오로 문제를 해결해야 한다.

---

## 📂 제공 파일

- `shell_basic` 실행 파일

---

## 🔗 External Links | 외부 링크
- 📘 Velog Write-up: [PwnWriteups #1 - 'shell_basic' Write-Up](https://velog.io/@0xqury/PwnWriteups-1-shellbasic-Write-Up)
- 🔒 Dreamhack: [https://dreamhack.io](https://dreamhack.io/wargame/challenges/410)