fn main() {
  let mut v = Vec::new();

  loop {
    let mut input = String::new();
    std::io::stdin().read_line(&mut input);

    input.pop();

    if input.is_empty(){
      break;
    }

    v.push(input);
  }

  v.iter().for_each(|s| {
    let answer = char_checker(s);
    println!("{} {} {} {}", answer[0], answer[1], answer[2], answer[3]);
  });
}

fn char_checker(s: &String) -> [u32;4]
{
  let mut ret = [0,0,0,0];

  for c in s.chars() {
    if c == ' ' {
      ret[3] += 1;
    } else if c >= 'a' && c <= 'z' {
      ret[0] += 1;
    } else if c >= '0' && c <= '9' {
      ret[2] += 1;
    } else {
      ret[1] += 1;
    }
  }
  ret
}

