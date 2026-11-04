# Lab 2 — Linux Navigation and File Management: individual report-
- Student name/ID: Nhel Sokunthika/e20230191
- Ubuntu username: gic-nhel-sokunthika
- My values (`oslab values lab2`): file1 = sales north.txt, file2 = vendor list.txt, owner = Sales, reader = HR, third = Marketing
- Files: `evidence/paths.txt`, `evidence/tree.txt`, `evidence/checkpoint.txt`

## What I Did

| Step | My command | Current folder when I ran it |
|---|---|---|
| Move the first file (relative destination) | `mv -- "$file1" ../reports/` | `lab2/incoming` |
| Move the second file (absolute paths) | `mv -- "$OSLAB_WORKSPACE/lab2/incoming/$file2" "$OSLAB_WORKSPACE/lab2/reports/"` | `lab2` |
| Read the report from my reader department (relative path) |`cat "../$owner/$file1"` (that is, `cat "../Sales/sales north.txt"`) | `lab2/Te>
| The path error I made on purpose, and its message |`cat "reports/$file1"` → `cat: 'reports/sales north.txt': No such file or directory` | >
| The relative path that fixed it |`../../reports/sales north.txt` | `lab2/TechCorp/HR` |

## Explanation

A correct file name can still give "No such file or directory" because a relative path
starts from the folder I am standing in, not from the lab folder. The file
`sales north.txt` exists in `reports/`, but from `TechCorp/HR` there is no `reports`
folder, so `reports/sales north.txt` points to a place that does not exist.
The fix is to climb two folders (`..` to `TechCorp`, `..` again to `lab2`) and then go
down into `reports`. An absolute path avoids this problem because it starts from `/`
and works from any folder. My prediction `incoming/reports` was wrong for the same
reason: from `incoming/` the right path to the neighbor folder is `../reports`.

## What My Tests Do Not Prove

`ls` only shows that a name exists in a folder, not what is inside the file, and `cmp`
only shows that the two copies are identical to each other. Neither proves that the
contents are correct or that they match the original from before I moved it, unless Isaved that content in Core 1.

## Plus / Challenge (only if you did them)

I did not do that.
