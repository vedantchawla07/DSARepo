import java.util.List;
public class Main {

    public static int minimumNumberOfPages(List<Integer> pages, int days) {
        int result = Integer.MAX_VALUE;
        int low = 1;
        int high = getMaximumValue(pages);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int total = countOfTotalDays(pages, mid);

            if (total <= days) {
                result = Math.min(result, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (result == Integer.MAX_VALUE) {
            return -1;
        } else {
            return result;
        }
    }

    private static int getMaximumValue(List<Integer> pages) {
        int max = Integer.MIN_VALUE;
        for (int page : pages) {
            if (page > max) {
                max = page;
            }
        }
        return max;
    }

    private static int countOfTotalDays(List<Integer> pages, int numPages) {
        int total = 0;
        for (int pageCount : pages) {
            total += (pageCount + numPages - 1) / numPages;
        }
        return total;
    }
