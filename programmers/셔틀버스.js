let nextBusArriveAt = '09:00';
let iter = 0;

function solution(n, t, m, timetable) {
  timetable.sort();

  let mm;
  while(n>1) {
    mm = m;
    while(mm--) {
      if(iter < timetable.length && timetable[iter] <= nextBusArriveAt ) {
        iter++;
      } else {
        break;
      }
    }

    nextBusArriveAt = addTime(nextBusArriveAt, t);
    n--;
  }


  mm = m;
  while(mm--) {
    if(iter < timetable.length && timetable[iter] <= nextBusArriveAt ) {
      iter++;
    } else {
      break;
    }
  }

  if(mm < 0) {
    return addTime(timetable[iter-1], -1);
  }

  return nextBusArriveAt;
}

function addTime(time, addMinute) {
  let [hour, minute] = time.split(':');

  let addHour = 0;
  minute = Number(minute) + Number(addMinute);

  if(minute >= 60) {
    minute -= 60;
    addHour++;
  }
  if(minute < 0) {
    minute = 60 + minute;
    addHour--;
  }

  hour = Number(hour) + addHour;

  if(hour < 0) {
    hour += 24;
  }

  if(hour >= 24) {
    hour -= 24;
  }

  return `${numberToString(hour)}:${numberToString(minute)}`;
}

function numberToString(num) {
  return num < 10 ? `0${num}` : `${num}`;
}

