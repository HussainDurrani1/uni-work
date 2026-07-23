-- ============================================================
--  Social Media Database System
--  University of Central Punjab  |  Section D7
--  Group: Talha Khurram, Hussain Durrani, Ali Hamza
-- ============================================================

-- ─────────────────────────────────────────────────────────────
DROP DATABASE IF EXISTS social_media_db;
CREATE DATABASE social_media_db CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
USE social_media_db;

SET FOREIGN_KEY_CHECKS = 0;   -- allow drops in any order during dev

-- ─────────────────────────────────────────────────────────────
--  1.  CREATE TABLES
-- ─────────────────────────────────────────────────────────────

-- 1.1  USERS
CREATE TABLE Users (
    user_id          INT            PRIMARY KEY AUTO_INCREMENT,
    username         VARCHAR(50)    NOT NULL UNIQUE,
    email            VARCHAR(100)   NOT NULL UNIQUE,
    password_hash    VARCHAR(255)   NOT NULL,
    full_name        VARCHAR(100),
    bio              TEXT,
    profile_picture  VARCHAR(255),
    gender           ENUM('Male','Female','Other'),
    date_of_birth    DATE,
    created_at       DATETIME       DEFAULT CURRENT_TIMESTAMP
);

-- 1.2  POSTS
CREATE TABLE Posts (
    post_id     INT            PRIMARY KEY AUTO_INCREMENT,
    content     TEXT           NOT NULL,
    privacy     ENUM('Public','Friends','Private') DEFAULT 'Public',
    created_at  DATETIME       DEFAULT CURRENT_TIMESTAMP,
    updated_at  DATETIME       DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    user_id     INT            NOT NULL,
    FOREIGN KEY (user_id) REFERENCES Users(user_id) ON DELETE CASCADE
);

-- 1.3  POST MEDIA
CREATE TABLE Post_Media (
    media_id    INT            PRIMARY KEY AUTO_INCREMENT,
    media_url   VARCHAR(255)   NOT NULL,
    media_type  ENUM('Image','Video') NOT NULL,
    post_id     INT            NOT NULL,
    FOREIGN KEY (post_id) REFERENCES Posts(post_id) ON DELETE CASCADE
);

-- 1.4  COMMENTS  (self-referencing for nested replies)
CREATE TABLE Comments (
    comment_id        INT       PRIMARY KEY AUTO_INCREMENT,
    comment_text      TEXT      NOT NULL,
    created_at        DATETIME  DEFAULT CURRENT_TIMESTAMP,
    post_id           INT       NOT NULL,
    user_id           INT       NOT NULL,
    parent_comment_id INT       DEFAULT NULL,
    FOREIGN KEY (post_id)           REFERENCES Posts(post_id)    ON DELETE CASCADE,
    FOREIGN KEY (user_id)           REFERENCES Users(user_id)    ON DELETE CASCADE,
    FOREIGN KEY (parent_comment_id) REFERENCES Comments(comment_id) ON DELETE SET NULL
);

-- 1.5  FOLLOWERS  (composite PK = follower + following)
CREATE TABLE Followers (
    follower_id  INT      NOT NULL,
    following_id INT      NOT NULL,
    followed_at  DATETIME DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (follower_id, following_id),
    FOREIGN KEY (follower_id)  REFERENCES Users(user_id) ON DELETE CASCADE,
    FOREIGN KEY (following_id) REFERENCES Users(user_id) ON DELETE CASCADE
);

-- 1.6  MESSAGES
CREATE TABLE Messages (
    message_id   INT            PRIMARY KEY AUTO_INCREMENT,
    message_text TEXT           NOT NULL,
    is_seen      BOOLEAN        DEFAULT FALSE,
    sent_at      DATETIME       DEFAULT CURRENT_TIMESTAMP,
    sender_id    INT            NOT NULL,
    receiver_id  INT            NOT NULL,
    FOREIGN KEY (sender_id)   REFERENCES Users(user_id) ON DELETE CASCADE,
    FOREIGN KEY (receiver_id) REFERENCES Users(user_id) ON DELETE CASCADE
);

-- 1.7  SAVED POSTS
CREATE TABLE Saved_Posts (
    user_id   INT      NOT NULL,
    post_id   INT      NOT NULL,
    saved_at  DATETIME DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (user_id, post_id),
    FOREIGN KEY (user_id) REFERENCES Users(user_id) ON DELETE CASCADE,
    FOREIGN KEY (post_id) REFERENCES Posts(post_id) ON DELETE CASCADE
);

-- 1.8  POST LIKES
CREATE TABLE Post_Likes (
    user_id   INT      NOT NULL,
    post_id   INT      NOT NULL,
    liked_at  DATETIME DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (user_id, post_id),
    FOREIGN KEY (user_id) REFERENCES Users(user_id) ON DELETE CASCADE,
    FOREIGN KEY (post_id) REFERENCES Posts(post_id) ON DELETE CASCADE
);

-- 1.9  COMMENT LIKES
CREATE TABLE Comment_Likes (
    user_id    INT      NOT NULL,
    comment_id INT      NOT NULL,
    liked_at   DATETIME DEFAULT CURRENT_TIMESTAMP,
    PRIMARY KEY (user_id, comment_id),
    FOREIGN KEY (user_id)    REFERENCES Users(user_id)    ON DELETE CASCADE,
    FOREIGN KEY (comment_id) REFERENCES Comments(comment_id) ON DELETE CASCADE
);

-- 1.10  NOTIFICATIONS
CREATE TABLE Notifications (
    notification_id    INT            PRIMARY KEY AUTO_INCREMENT,
    notification_type  ENUM('Like','Comment','Follow','Message') NOT NULL,
    reference_id       INT,
    is_read            BOOLEAN  DEFAULT FALSE,
    created_at         DATETIME DEFAULT CURRENT_TIMESTAMP,
    user_id            INT      NOT NULL,   -- recipient
    triggered_by       INT      NOT NULL,   -- actor
    FOREIGN KEY (user_id)      REFERENCES Users(user_id) ON DELETE CASCADE,
    FOREIGN KEY (triggered_by) REFERENCES Users(user_id) ON DELETE CASCADE
);

SET FOREIGN_KEY_CHECKS = 1;

-- ─────────────────────────────────────────────────────────────
--  2.  SAMPLE DATA
-- ─────────────────────────────────────────────────────────────

-- 2.1  USERS  (10 users)
INSERT INTO Users (username, email, password_hash, full_name, bio, profile_picture, gender, date_of_birth) VALUES
('hussain_d',   'hussain@ucp.edu.pk',  'hash1', 'Hussain Durrani',  'CS student @ UCP',           'hussain.jpg',  'Male',   '2005-03-15'),
('talha_k',     'talha@ucp.edu.pk',    'hash2', 'Talha Khurram',    'Tech enthusiast',            'talha.jpg',    'Male',   '2004-11-20'),
('ali_h',       'ali@ucp.edu.pk',      'hash3', 'Ali Hamza',        'Loves DSA',                  'ali.jpg',      'Male',   '2005-07-08'),
('sara_m',      'sara@gmail.com',      'hash4', 'Sara Malik',       'Photography & travel',       'sara.jpg',     'Female', '2003-01-25'),
('haseeb_r',    'haseeb@gmail.com',    'hash5', 'Haseeb Rehman',    'Foodie | Coder',             'haseeb.jpg',   'Male',   '2004-06-30'),
('zara_a',      'zara@gmail.com',      'hash6', 'Zara Ahmed',       'Art & design',               'zara.jpg',     'Female', '2005-09-12'),
('usman_b',     'usman@gmail.com',     'hash7', 'Usman Baig',       'Gaming & anime',             'usman.jpg',    'Male',   '2003-12-01'),
('aisha_n',     'aisha@gmail.com',     'hash8', 'Aisha Nadeem',     'Bookworm',                   'aisha.jpg',    'Female', '2004-04-17'),
('bilal_q',     'bilal@gmail.com',     'hash9', 'Bilal Qureshi',    'Entrepreneur',               'bilal.jpg',    'Male',   '2002-08-22'),
('nida_f',      'nida@gmail.com',      'hash10','Nida Farooq',      'Music & poetry',             'nida.jpg',     'Female', '2005-02-14');

-- 2.2  POSTS  (15 posts spread across users)
INSERT INTO Posts (content, privacy, user_id) VALUES
('Just finished implementing BFS in C++ 🔥',                            'Public',  1),
('Beautiful sunset from Lahore today 🌇',                               'Public',  4),
('New personal best at the gym 💪',                                      'Public',  5),
('Started reading "Clean Code" — highly recommend!',                    'Public',  8),
('Working on my first startup idea. Exciting times!',                   'Public',  9),
('Just deployed my portfolio website. Check it out!',                   'Public',  2),
('Missing home-cooked food 😢 Lahore ki biryani hits different',        'Friends', 3),
('Photography tip: golden hour is everything 📷',                       'Public',  4),
('DSA assignment submitted on time for once 😂',                        'Public',  1),
('Anime recommendation: Vinland Saga — masterpiece',                    'Public',  7),
('Eid Mubarak to everyone! 🌙',                                         'Public',  6),
('New AI tools are changing everything in tech',                        'Public',  9),
('Poem I wrote last night... "Stars above Lahore..."',                  'Friends', 10),
('Anyone else obsessed with Notion for productivity?',                  'Public',  2),
('Just hit 500 followers! Thank you all ❤️',                            'Public',  5);

-- 2.3  POST MEDIA
INSERT INTO Post_Media (media_url, media_type, post_id) VALUES
('bfs_code.png',      'Image', 1),
('sunset_lahore.jpg', 'Image', 2),
('gym_pr.jpg',        'Image', 3),
('portfolio.png',     'Image', 6),
('eid_pic.jpg',       'Image', 11),
('golden_hour1.jpg',  'Image', 8),
('golden_hour2.jpg',  'Image', 8),
('vinland.mp4',       'Video', 10);

-- 2.4  COMMENTS
INSERT INTO Comments (comment_text, post_id, user_id, parent_comment_id) VALUES
('Great work Hussain! BFS is tough',       1,  2,  NULL),  -- comment_id 1
('Thanks Talha! It took me hours 😅',      1,  1,  1),     -- reply to 1
('Which gym do you go to?',                3,  7,  NULL),  -- comment_id 3
('Power House Gym — best in Lahore!',      3,  5,  3),     -- reply to 3
('Love this photo Sara!',                  2,  6,  NULL),  -- comment_id 5
('Thank you Zara! 😍',                     2,  4,  5),     -- reply to 5
('Vinland Saga is goated 🔥',              10, 1,  NULL),  -- comment_id 7
('Season 2 is even better!',               10, 3,  7),     -- reply to 7
('I am also reading Clean Code!',          4,  2,  NULL),  -- comment_id 9
('Which chapter are you on?',              4,  8,  9),     -- reply to 9
('Congratulations on 500!',                15, 1,  NULL),  -- comment_id 11
('Love your content Haseeb!',              15, 4,  NULL),  -- comment_id 12
('Notion is life-changing!',               14, 5,  NULL),  -- comment_id 13
('Starting my startup too! DM me',         5,  3,  NULL),  -- comment_id 14
('This poem is beautiful Nida!',           13, 8,  NULL);  -- comment_id 15

-- 2.5  FOLLOWERS
INSERT INTO Followers (follower_id, following_id) VALUES
(1, 2), (1, 4), (1, 5), (1, 9),
(2, 1), (2, 3), (2, 9),
(3, 1), (3, 2), (3, 7),
(4, 5), (4, 6), (4, 8),
(5, 1), (5, 2), (5, 4),
(6, 4), (6, 10),
(7, 1), (7, 3), (7, 10),
(8, 4), (8, 9), (8, 10),
(9, 1), (9, 2),
(10, 4), (10, 6), (10, 8);

-- 2.6  MESSAGES
INSERT INTO Messages (message_text, is_seen, sender_id, receiver_id) VALUES
('Hey Talha, did you finish the assignment?',  TRUE,  1, 2),
('Yeah, just submitted! You?',                 TRUE,  2, 1),
('Still working on it 😅',                     TRUE,  1, 2),
('Let me know if you need help!',              FALSE, 2, 1),
('Sara your sunset photo was amazing!',        TRUE,  6, 4),
('Thank you so much Zara 😊',                 TRUE,  4, 6),
('Hey Bilal, interested in collaborating?',    FALSE, 3, 9),
('Sure! Tell me more about your idea',         FALSE, 9, 3),
('Haseeb which gym membership do you have?',  TRUE,  7, 5),
('Annual — totally worth it!',                 FALSE, 5, 7);

-- 2.7  SAVED POSTS
INSERT INTO Saved_Posts (user_id, post_id) VALUES
(1, 4), (1, 12),
(2, 1), (2, 9),
(3, 10), (3, 5),
(4, 8), (4, 11),
(5, 14), (5, 15),
(6, 13), (6, 2),
(7, 10), (7, 1),
(8, 4), (8, 13),
(9, 12), (9, 5),
(10, 2), (10, 13);

-- 2.8  POST LIKES
INSERT INTO Post_Likes (user_id, post_id) VALUES
(2, 1), (3, 1), (4, 1), (5, 1), (7, 1),          -- post 1 : 5 likes
(1, 2), (3, 2), (5, 2), (6, 2), (8, 2), (9, 2),  -- post 2 : 6 likes
(1, 3), (2, 3), (6, 3), (9, 3),                   -- post 3 : 4 likes
(1, 4), (2, 4), (5, 4), (7, 4),                   -- post 4 : 4 likes
(2, 5), (4, 5), (6, 5), (8, 5), (10, 5),          -- post 5 : 5 likes
(1, 6), (3, 6), (4, 6), (7, 6),                   -- post 6 : 4 likes
(2, 7), (4, 7), (6, 7),                           -- post 7 : 3 likes
(1, 8), (3, 8), (5, 8), (7, 8), (9, 8), (10, 8), -- post 8 : 6 likes
(2, 9), (6, 9), (8, 9),                           -- post 9 : 3 likes
(1, 10),(4, 10),(5, 10),(6, 10),(8, 10),           -- post 10: 5 likes
(1, 11),(2, 11),(3, 11),(4, 11),(5, 11),           -- post 11: 5 likes
(6, 11),(7, 11),(8, 11),(9, 11),(10,11),           -- post 11: +5 = 10 likes
(1, 12),(3, 12),(5, 12),(7, 12),(9, 12),           -- post 12: 5 likes
(2, 13),(4, 13),(6, 13),(8, 13),(10,13),           -- post 13: 5 likes
(1, 14),(3, 14),(5, 14),(7, 14),(9, 14),           -- post 14: 5 likes
(2, 15),(4, 15),(6, 15),(8, 15),(10,15);           -- post 15: 5 likes

-- 2.9  COMMENT LIKES
INSERT INTO Comment_Likes (user_id, comment_id) VALUES
(1, 1), (3, 1), (5, 1),
(2, 3), (4, 3), (6, 3),
(1, 5), (3, 5), (7, 5),
(2, 7), (4, 7), (6, 7), (8, 7),
(1, 9), (3, 9),
(5, 11),(6, 11),(7, 11),(9, 11),
(1, 13),(2, 13),(3, 13);

-- 2.10  NOTIFICATIONS
INSERT INTO Notifications (notification_type, reference_id, is_read, user_id, triggered_by) VALUES
('Like',     1,  TRUE,  1,  2),   -- Talha liked Hussain's post
('Like',     1,  TRUE,  1,  3),   -- Ali liked Hussain's post
('Comment',  1,  TRUE,  1,  2),   -- Talha commented on Hussain's post
('Follow',   NULL, TRUE, 1, 5),   -- Haseeb followed Hussain
('Like',     2,  FALSE, 4,  1),   -- Hussain liked Sara's post
('Comment',  2,  FALSE, 4,  6),   -- Zara commented on Sara's post
('Follow',   NULL, TRUE, 4, 5),   -- Haseeb followed Sara
('Like',     10, FALSE, 7,  1),   -- Hussain liked Usman's post
('Comment',  10, FALSE, 7,  3),   -- Ali commented on Usman's post
('Message',  NULL, FALSE,1, 2),   -- Talha messaged Hussain
('Follow',   NULL, FALSE,9, 3),   -- Ali followed Bilal
('Like',     11, TRUE,  6,  1),   -- Hussain liked Zara's post
('Comment',  15, FALSE, 5,  1),   -- Hussain commented on Haseeb's post
('Follow',   NULL, FALSE,10,8),   -- Aisha followed Nida
('Like',     13, FALSE, 10, 8);   -- Aisha liked Nida's poem post


-- ─────────────────────────────────────────────────────────────
--  3.  SAMPLE QUERIES
--      Demonstrating all required concepts
-- ─────────────────────────────────────────────────────────────

-- ══════════════════════════════════════════════════════════════
-- 3.1  JOINS
-- ══════════════════════════════════════════════════════════════

-- (a) INNER JOIN — Posts with their author info
SELECT p.post_id, u.username, u.full_name, p.content, p.privacy, p.created_at
FROM Posts p
INNER JOIN Users u ON p.user_id = u.user_id
ORDER BY p.created_at DESC;

-- (b) LEFT JOIN — All users and their posts (includes users with no posts)
SELECT u.user_id, u.username, p.post_id, p.content
FROM Users u
LEFT JOIN Posts p ON u.user_id = p.user_id
ORDER BY u.user_id;

-- (c) RIGHT JOIN — All posts and their comments (include posts with no comments)
SELECT p.post_id, p.content, c.comment_id, c.comment_text
FROM Comments c
RIGHT JOIN Posts p ON c.post_id = p.post_id
ORDER BY p.post_id;

-- (d) FULL OUTER JOIN (emulated with UNION) — 
--     All users + all posts even if no match on either side
SELECT u.username, p.post_id, p.content
FROM Users u LEFT JOIN Posts p ON u.user_id = p.user_id
UNION
SELECT u.username, p.post_id, p.content
FROM Users u RIGHT JOIN Posts p ON u.user_id = p.user_id;

-- (e) Multi-table JOIN — Comments with post content and commenter username
SELECT c.comment_id,
       u.username   AS commenter,
       p.content    AS on_post,
       c.comment_text,
       c.created_at
FROM Comments c
JOIN Users u ON c.user_id = u.user_id
JOIN Posts  p ON c.post_id = p.post_id
ORDER BY c.created_at;

-- (f) Self JOIN via Followers — Who follows whom (names instead of IDs)
SELECT f1.username AS follower, f2.username AS following
FROM Followers fl
JOIN Users f1 ON fl.follower_id  = f1.user_id
JOIN Users f2 ON fl.following_id = f2.user_id
ORDER BY f1.username;


-- ══════════════════════════════════════════════════════════════
-- 3.2  AGGREGATE FUNCTIONS
-- ══════════════════════════════════════════════════════════════

-- (a) COUNT, MAX, MIN, AVG, SUM — Overall platform stats
SELECT
    COUNT(DISTINCT u.user_id)    AS total_users,
    COUNT(DISTINCT p.post_id)    AS total_posts
FROM Users u, Posts p;

SELECT
    COUNT(*)                   AS total_likes,
    MAX(liked_at)              AS most_recent_like,
    MIN(liked_at)              AS oldest_like
FROM Post_Likes;

-- (b) Likes per post (aggregate on junction table)
SELECT post_id, COUNT(*) AS like_count
FROM Post_Likes
GROUP BY post_id
ORDER BY like_count DESC;

-- (c) Average comments per post
SELECT AVG(comment_count) AS avg_comments_per_post
FROM (
    SELECT post_id, COUNT(*) AS comment_count
    FROM Comments
    GROUP BY post_id
) AS cc;


-- ══════════════════════════════════════════════════════════════
-- 3.3  GROUP BY  +  HAVING
-- ══════════════════════════════════════════════════════════════

-- (a) GROUP BY — Number of posts per user
SELECT u.username, COUNT(p.post_id) AS post_count
FROM Users u
LEFT JOIN Posts p ON u.user_id = p.user_id
GROUP BY u.user_id, u.username
ORDER BY post_count DESC;

-- (b) HAVING — Users who have more than 1 post
SELECT u.username, COUNT(p.post_id) AS post_count
FROM Users u
LEFT JOIN Posts p ON u.user_id = p.user_id
GROUP BY u.user_id, u.username
HAVING post_count > 1
ORDER BY post_count DESC;

-- (c) GROUP BY — Total likes received per user
SELECT u.username, COUNT(pl.post_id) AS total_likes_received
FROM Users u
JOIN Posts p    ON p.user_id = u.user_id
JOIN Post_Likes pl ON pl.post_id = p.post_id
GROUP BY u.user_id, u.username
ORDER BY total_likes_received DESC;

-- (d) HAVING — Users whose posts collectively received more than 5 likes
SELECT u.username, COUNT(pl.post_id) AS total_likes_received
FROM Users u
JOIN Posts p    ON p.user_id = u.user_id
JOIN Post_Likes pl ON pl.post_id = p.post_id
GROUP BY u.user_id, u.username
HAVING total_likes_received > 5
ORDER BY total_likes_received DESC;

-- (e) GROUP BY — Follower count per user
SELECT u.username, COUNT(f.follower_id) AS followers
FROM Users u
LEFT JOIN Followers f ON f.following_id = u.user_id
GROUP BY u.user_id, u.username
ORDER BY followers DESC;

-- (f) HAVING — Users with more than 3 followers
SELECT u.username, COUNT(f.follower_id) AS followers
FROM Users u
LEFT JOIN Followers f ON f.following_id = u.user_id
GROUP BY u.user_id, u.username
HAVING followers > 3
ORDER BY followers DESC;

-- (g) Notifications grouped by type
SELECT notification_type, COUNT(*) AS count
FROM Notifications
GROUP BY notification_type;

-- (h) Unread notifications per user (HAVING)
SELECT u.username, COUNT(n.notification_id) AS unread_count
FROM Users u
JOIN Notifications n ON n.user_id = u.user_id
WHERE n.is_read = FALSE
GROUP BY u.user_id, u.username
HAVING unread_count >= 1
ORDER BY unread_count DESC;


-- ══════════════════════════════════════════════════════════════
-- 3.4  SUBQUERIES  (non-correlated)
-- ══════════════════════════════════════════════════════════════

-- (a) Users who have never posted
SELECT username, full_name
FROM Users
WHERE user_id NOT IN (SELECT DISTINCT user_id FROM Posts);

-- (b) The most liked post (single scalar subquery)
SELECT post_id, content
FROM Posts
WHERE post_id = (
    SELECT post_id
    FROM Post_Likes
    GROUP BY post_id
    ORDER BY COUNT(*) DESC
    LIMIT 1
);

-- (c) Posts that have at least one comment
SELECT post_id, content
FROM Posts
WHERE post_id IN (SELECT DISTINCT post_id FROM Comments);

-- (d) Users who follow the most-followed user
SELECT username FROM Users
WHERE user_id IN (
    SELECT follower_id FROM Followers
    WHERE following_id = (
        SELECT following_id FROM Followers
        GROUP BY following_id
        ORDER BY COUNT(*) DESC
        LIMIT 1
    )
);

-- (e) Posts with above-average likes
SELECT p.post_id, p.content, COUNT(pl.user_id) AS likes
FROM Posts p
JOIN Post_Likes pl ON pl.post_id = p.post_id
GROUP BY p.post_id, p.content
HAVING likes > (
    SELECT AVG(like_count)
    FROM (
        SELECT COUNT(*) AS like_count FROM Post_Likes
        GROUP BY post_id
    ) AS avg_table
);


-- ══════════════════════════════════════════════════════════════
-- 3.5  CORRELATED SUBQUERIES
-- ══════════════════════════════════════════════════════════════

-- (a) Users who have liked every post they commented on
SELECT u.username FROM Users u
WHERE NOT EXISTS (
    SELECT c.post_id FROM Comments c
    WHERE c.user_id = u.user_id
    AND c.post_id NOT IN (
        SELECT pl.post_id FROM Post_Likes pl
        WHERE pl.user_id = u.user_id
    )
);

-- (b) Each user's most recent post (correlated in FROM / lateral-style using MAX)
SELECT u.username,
       p.post_id,
       p.content,
       p.created_at
FROM Posts p
JOIN Users u ON p.user_id = u.user_id
WHERE p.created_at = (
    SELECT MAX(p2.created_at)
    FROM Posts p2
    WHERE p2.user_id = p.user_id   -- correlated on outer table
);

-- (c) Posts that received more likes than the author's own average
SELECT p.post_id, p.content,
       (SELECT COUNT(*) FROM Post_Likes pl WHERE pl.post_id = p.post_id) AS likes
FROM Posts p
WHERE (SELECT COUNT(*) FROM Post_Likes pl WHERE pl.post_id = p.post_id)
      >
      (SELECT AVG(cnt) FROM (
           SELECT COUNT(*) AS cnt FROM Post_Likes pl2
           JOIN Posts p3 ON pl2.post_id = p3.post_id
           WHERE p3.user_id = p.user_id    -- correlated to outer Posts
           GROUP BY pl2.post_id
       ) AS author_avg);

-- (d) Users who have sent messages but never received any (EXISTS / NOT EXISTS)
SELECT u.username
FROM Users u
WHERE EXISTS     (SELECT 1 FROM Messages m WHERE m.sender_id   = u.user_id)
  AND NOT EXISTS (SELECT 1 FROM Messages m WHERE m.receiver_id = u.user_id);

-- (e) Comments that received more likes than the average comment-like count
SELECT c.comment_id, c.comment_text,
       (SELECT COUNT(*) FROM Comment_Likes cl WHERE cl.comment_id = c.comment_id) AS likes
FROM Comments c
WHERE (SELECT COUNT(*) FROM Comment_Likes cl WHERE cl.comment_id = c.comment_id)
      >
      (SELECT AVG(lc) FROM (
           SELECT COUNT(*) AS lc
           FROM Comment_Likes
           GROUP BY comment_id
       ) AS avg_cl);


-- ══════════════════════════════════════════════════════════════
-- 3.6  SET OPERATIONS
-- ══════════════════════════════════════════════════════════════

-- (a) UNION — Users who have posted OR commented (distinct list)
SELECT user_id FROM Posts
UNION
SELECT user_id FROM Comments;

-- (b) UNION ALL — Every user interaction (posts + comments, with duplicates)
SELECT user_id, 'Post'    AS activity_type FROM Posts
UNION ALL
SELECT user_id, 'Comment' AS activity_type FROM Comments
ORDER BY user_id;

-- (c) INTERSECT (emulated) — Users who have BOTH posted AND commented
SELECT user_id FROM Posts
WHERE user_id IN (SELECT user_id FROM Comments);

-- (d) EXCEPT / MINUS (emulated) — Users who posted but have NOT commented
SELECT DISTINCT user_id FROM Posts
WHERE user_id NOT IN (SELECT DISTINCT user_id FROM Comments);

-- (e) Users who liked a post AND saved that same post (intersection via INTERSECT emulation)
SELECT user_id FROM Post_Likes
WHERE post_id = 1
  AND user_id IN (
      SELECT user_id FROM Saved_Posts WHERE post_id = 1
  );

-- ══════════════════════════════════════════════════════════════
-- END OF FILE
-- ══════════════════════════════════════════════════════════════
