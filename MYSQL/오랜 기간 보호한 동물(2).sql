-- 코드를 입력하세요
SELECT ANIMAL_INS.ANIMAL_ID,ANIMAL_INS.NAME 
FROM ANIMAL_INS LEFT JOIN ANIMAL_OUTS ON ANIMAL_INS.ANIMAL_ID = ANIMAL_OUTS.ANIMAL_ID
WHERE ANIMAL_OUTS.ANIMAL_ID is not NULL
ORDER BY ANIMAL_INS.DATETIME-ANIMAL_OUTS.DATETIME
LIMIT 2