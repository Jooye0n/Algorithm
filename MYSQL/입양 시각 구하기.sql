-- 코드를 입력하세요
SELECT HOUR(DATETIME) AS HOUR, COUNT(HOUR(DATETIME)) FROM ANIMAL_OUTS 
GROUP BY HOUR HAVING HOUR>=9 && HOUR<=19
ORDER BY HOUR