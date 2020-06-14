use std::io;
use std::cmp::min;

fn main() {
    let mut num = String::new();
    io::stdin().read_line(&mut num)
        .expect("Failed to read line");
    let num: usize = num.trim().parse()
        .expect("please type a number");

    let mut cache: Vec<i32> = vec![1e6 as i32 + 1; num + 1];
    let mut begin: Vec<i32> = vec![0; num + 1];
    cache[1] = 0;

    for idx in 2..num+1{
        if idx < 2 {
            continue
        }

        cache[idx] = min(cache[idx], cache[idx-1] + 1);
        begin[idx] = (idx - 1) as i32;
        if idx % 2 == 0 {
            cache[idx] = min(cache[idx], cache[idx/2] + 1);
            begin[idx] = (idx / 2) as i32;
        }
        if idx % 3 == 0 {
            cache[idx] = min(cache[idx], cache[idx/3] + 1);
            begin[idx] = (idx / 3) as i32;
        }
    }

    println!("{}", cache[num]);

    let mut answer: Vec<i32> = Vec::new();
    construct_answer(&cache, &mut answer, num);

    answer.iter().for_each(|num| print!("{} ", num));
    println!();
}

fn construct_answer(cache: &Vec<i32>, answer: &mut Vec<i32>, target: usize) {
    answer.push(target as i32);
    if target == 1 {
        return
    }

    if target % 3 == 0 && cache[target] - cache[target/3] == 1 {
        construct_answer(cache, answer, target / 3);
    } else if target % 2 == 0 && cache[target] - cache[target/2] == 1 {
        construct_answer(cache, answer, target / 2);
    } else {
        construct_answer(cache, answer, target - 1);
    }
}

