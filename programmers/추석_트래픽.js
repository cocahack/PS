function solution(lines) {
  let answer = 0;

  const events = [];

  lines.map(line => line.split(' '))
       .forEach(([date, time, len]) => {
         const end = new Date(`${date} ${time}`).getTime();
         events.push({ start: end - secondStringToMill(len) , end  })
       });

  for(let i=0; i<events.length; ++i) {
    const e = events[i];
    const ranges = [
      {start: e.start, end: e.start+999},
      {start: e.start-999, end: e.start},
      {start: e.end-999, end: e.end},
      {start: e.end, end: e.end+999},
    ];
    const intersectCounts = [1,1,1,1];

    for(let j = 0; j<events.length; ++j) {
      if(i === j) continue;
      ranges.forEach((range, idx) => {
        if(isIntersect(range, events[j])) intersectCounts[idx]++;
      });
    }

    intersectCounts.forEach(c => answer = Math.max(answer, c));
  }

  return answer;
}

function secondStringToMill(secStr) {
  let sec = Number(secStr.substr(0, secStr.length-1)) * 1000;
  return sec ? sec - 1 : 0;
}

function isIntersect(a, b) {
  return (a.start <= b.start && b.start <= a.end)
    || (a.start <= b.end && b.end <= a.end)
    || (b.start <= a.start && a.start <= b.end)
    || (b.start <= a.end && a.end <= b.end);
}

