# Maintaining the CSES archive

Use the current [CSES problem set](https://cses.fi/problemset/) as the source for section names, problem titles, ordering, and totals.

- Store each accepted C++ solution as `<Section Title>/<Problem Title>.cpp`.
- Copy the latest accepted C++ submission from the owner's CSES account. Preserve its code, indentation, and intentional blank lines; normalize CRCRLF/CRLF line endings to LF without inserting blank lines.
- Prepend a metadata comment containing `Problem`, `Link`, `Author: Tamzid Tariq`, `Date`, and `Status: Accepted ✓`.
- Set `Date` to the first accepted submission date displayed by CSES, rather than the download date. Link the selected accepted submission in the section README.
- Update the section index and root progress table together. Count distinct solved problems, rather than submissions, and list unsolved tasks without placeholder source files.
- Verify every archived code body against the accepted submission after normalizing line endings. Compile using the submission's C++ standard where practical.
- Keep credentials, account instructions (`Agents.MD`), session cookies, and download caches out of version control. The local instruction file and `.cses-cache/` are ignored.

The archive records the owner's submitted solutions. Algorithm rewrites should be accepted on CSES before replacing an archived source.
