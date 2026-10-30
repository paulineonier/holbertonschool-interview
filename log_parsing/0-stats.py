
#!/usr/bin/python3
"""Parse logs and print statistics."""

import re
import sys


STATUS_CODES = (200, 301, 400, 401, 403, 404, 405, 500)

LOG_PATTERN = re.compile(
    r'^(\S+) - \[(.*?)\] "GET /projects/260 HTTP/1\.1" (\d+) (\d+)$'
)


def print_stats(total_size, status_counts):
    """Print the accumulated statistics."""
    print("File size: {}".format(total_size))

    for code in STATUS_CODES:
        if status_counts[code] > 0:
            print("{}: {}".format(code, status_counts[code]))


def main():
    """Read stdin and compute log metrics."""
    total_size = 0
    status_counts = {code: 0 for code in STATUS_CODES}
    lines_read = 0

    try:
        for line in sys.stdin:
            lines_read += 1
            match = LOG_PATTERN.fullmatch(line.rstrip("\n"))

            if match:
                status = int(match.group(3))
                file_size = int(match.group(4))

                total_size += file_size

                if status in status_counts:
                    status_counts[status] += 1

            if lines_read % 10 == 0:
                print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        print_stats(total_size, status_counts)


if __name__ == "__main__":
    main()
